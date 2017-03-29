#include <stdlib.h>
#include <libpq-fe.h>
#include <string.h>
#include <unistd.h>
#include <stdio.h>
#define MAX 100

// Arkadiusz Klein
// 238138
// grupa 3

/*	przyklady wywolania:
./1 = samo wczytanie pliku i ew dodanie danych
./1 tabela1 strona.html = to co wyzej + druk instejacej w bazie tabela1 do stona.html
 ZEBY COS DRUKOWAC MUSZE BYC 2 LUB WIECEJ ARGUMENTOW (oprocz wywalania)
./1 tabela1 ... tabelaN strona2.html = to co wyzej, tylko ze drukuje wszystkie tabele 1 do N w pliku strona2.html
*/

void doSQL(PGconn *conn, char *command)
{
 	PGresult *result;
 	printf("%s\n", command);
  	result = PQexec(conn, command);
  	printf("status is     : %s\n", PQresStatus(PQresultStatus(result)));
  	printf("#rows affected: %s\n", PQcmdTuples(result));
  	printf("result message: %s\n", PQresultErrorMessage(result));
  	switch(PQresultStatus(result)) 
	{
  		case PGRES_TUPLES_OK:
   		{
      		int n = 0, m = 0;
     		int nrows   = PQntuples(result);
     		int nfields = PQnfields(result);
      		printf("number of rows returned   = %d\n", nrows);
      		printf("number of fields returned = %d\n", nfields);
      		for(m = 0; m < nrows; m++) 
			{
				for(n = 0; n < nfields; n++)
	  				printf(" %s = %s", PQfname(result, n),PQgetvalue(result,m,n));
				printf("\n");
      		}
    	}
  	}
  	PQclear(result);
}

void HTMLprint(PGconn * conn, int ile, char *argv[])
{
	PGresult *result;
	char polec[150];
	int i;
	int n;
    int m;
	FILE * druk = fopen(argv[ile-1], "w+"); //plik html generowanie
	fprintf(druk,"<!DOCTYPE html> \n <html lang=\"pl\"> \n <head> \n <meta charset=\"utf-8\"> \n <meta name=\"viewport\" content=\"width=device-width, initial-scale=1.0\"> \n <title>Dane z tabel</title> \n <style> \n"); //header
	//tutaj styl:
	fprintf(druk,"body {font-family: \"Helvetica Neue\", Helvetica, Arial%cfont-size: 14px%cline-height: 20px%cfont-weight: 400%ccolor: #3b3b3b%c-webkit-font-smoothing: antialiased%cfont-smoothing: antialiased%cbackground: #2b2b2b}.wrapper {margin: 0 auto%cpadding: 40px%cmax-width: 800px}.table {margin: 0 auto%cbox-shadow: 0 1px 3px rgba(0, 0, 0, 0.2)%cdisplay: table}@media screen and (max-width: 580px) {.table {display: block}}h1{color:white%c text-align: center}.row {display: table-row%cbackground: #f6f6f6}.row:nth-of-type(odd) {background: #e9e9e9}.row.header {font-weight: 900%ccolor: #ffffff%cbackground: #2980b9}@media screen and (max-width: 580px) {.row {padding: 8px 0%cdisplay: block}}.cell {padding: 6px 12px%cdisplay: table-cell}@media screen and (max-width: 580px) {.cell {padding: 2px 12px%cdisplay: block}}\n</style></head>\n",59,59,59,59,59,59,59,59,59,59,59,59,59,59,59,59,59,59);
	fprintf(druk,"<body>\n <div class=\"wrapper\">");
	for(i=1;i<ile-1;i++)
	{
		sprintf(polec,"SELECT * FROM %s",argv[i]);
  		result = PQexec(conn, polec);
  		switch(PQresultStatus(result)) 
		{
  			case PGRES_TUPLES_OK:
   			{
   				fprintf(druk,"<h1>Tabela %s</h1>\n<br>\n",argv[i]);
      			n=0;
      			m=0;
     			int nrows   = PQntuples(result); //wiersze
     			int nfields = PQnfields(result); //kolumny
				fprintf(druk,"<div class=\"table\">\n<div class=\"row header\">\n");
				for(n=0;n<nfields;n++) //druk nazwy kolumn
					fprintf(druk,"<div class=\"cell\">%s</div>\n",PQfname(result, n));
				fprintf(druk,"</div>\n");
      			for(m = 0; m < nrows; m++) //druk zawartosci
				{
					fprintf(druk,"<div class=\"row\">\n");
					for(n = 0; n < nfields; n++)
	  					fprintf(druk,"<div class=\"cell\">%s</div>\n",PQgetvalue(result,m,n));
					fprintf(druk,"</div>\n");
      			}
      			fprintf(druk,"</div> <br><br>\n ");
      			printf("Wydrukowano tabele %s do %s\n",argv[i],argv[ile-1]);
    		}
  		}
  		PQclear(result);
  	}
  	fprintf(druk,"</div>\n</body> \n </html>");
  	fclose(druk);
}

int main(int argc, char *argv[])
{
	char login[20];
	char dbname[20];
	char *password;
	printf("Podaj login\n");
	scanf("%s",login);
	printf("Podaj dbname\n");
	scanf("%s",dbname);
	char info[100];
	strcpy(info,"host=localhost port=5432 dbname=");
	strcat(info,dbname);
	strcat(info," user=");
	strcat(info,login);
	strcat(info," password=");
	password=getpass("Podaj haslo\n");
	strcat(info,password);
	password=NULL;
  	// próba po³±czenia
  	PGconn *con = PQconnectdb(info);
  	if(PQstatus(con) == CONNECTION_OK) 
  	{
    	printf("Polaczono\n");
    	printf("PGDBNAME   = %s\n",PQdb(con));
    	printf("PGUSER     = %s\n",PQuser(con));
    	printf("PGPASSWORD = ***********\n");
    	printf("PGHOST     = %s\n",PQhost(con));
    	printf("PGPORT     = %s\n",PQport(con));
    	printf("OPTIONS    = %s\n\n",PQoptions(con));
    	printf("Podaj nazwe pliku .csv do wczytania\n"); // osoba otworzy osoba.csv
    	char nazwa[30];
    	char nazwa2[30];
    	scanf("%s",nazwa);
    	strcpy(nazwa2,nazwa);
    	strcat(nazwa2,".csv");
    	FILE * dane = fopen(nazwa2, "r");
    	if (dane == NULL)
		{
   	 	    printf("Blad odczytu pliku! Potrzeba pliku %s z danymi\n",nazwa2);
    	    return 0;
   		}
   		else
   		{
   			printf("Otwarto plik %s\n",nazwa2);
   			char polecenie[1000];
   			int i;
			int j=0;
			int k=0;
			char temp;
			char koniec='\n';
			char next=';';
			char tab[MAX][MAX][MAX];
			int dozmiany[MAX];
			i=0;
			int ileK;
			
    		while(fscanf(dane,"%c",&temp)==1) //czytanie zawartosci pliku
			{
				if (temp==next) 
				{
					if(tab[k][i][j-1]!=0 && k!=0 && i!=0)
						tab[k][i][j]=(char)39;
					if(20<(j-1) && k!=0) //ew przekorczenie VARCHAR(20)
					{
						j--;
						if(dozmiany[i]<j)
							dozmiany[i]=j;
					}
					j=0;
					if(tab[k][i][j]==0)
						strcpy(tab[k][i],"NULL");
					i++;
				}
				else if (temp==koniec) 
				{
					if(tab[k][i][j-1]!=0 && k!=0 && i!=0)
						tab[k][i][j]=(char)39;
					if(20<(j-1) && k!=0) //ew przekorczenie VARCHAR(20)
					{
						j--;
						if(dozmiany[i]<j)
							dozmiany[i]=j;
					}
					j=0;
					if(tab[k][i][j]==0)
						strcpy(tab[k][i],"NULL");
					if(k==0) //sprawdzanie ilosc kolumn dla 1 linijki
					{
						if(i<5)
						{
							printf("Blad, plik powinien miec conajmniej 6 kolumn!\n");
							return EXIT_FAILURE;
						}
						else
						{
							ileK=i;
							for(i=0;i<ileK;i++)
							dozmiany[i]=20;
						}
					}
					i=0;
					k++;
				}
				else
				{
					if(j==0 && k!=0 && i!=0)
					{
						tab[k][i][j]=(char)39;
						j++;
					}
					tab[k][i][j]=temp;
					j++;
				}
			}
			int max=k;
   			k=0;
   			char kawalek[MAX];
   			sprintf(polecenie, "DROP TABLE %s",nazwa);
   			doSQL(con,polecenie);
			sprintf(polecenie,"CREATE TABLE %s(%s INTEGER PRIMARY KEY UNIQUE",nazwa,tab[k][0]);
			for(i=1;i<=ileK;i++)
			{
				sprintf(kawalek,", %s VARCHAR(20)",tab[k][i]);
				strcat(polecenie,kawalek);
			}
			strcat(polecenie,")");
            doSQL(con,polecenie);
            //ew zmiana wielkosci VARCHAR
            //Dla tego przykladu powinno zmienic mail na VARCHAR(30), poniewaz osoba nr 8 ma dlugiego maila
            for(i=0;i<=ileK;i++)
            	if(dozmiany[i]!=20)
            	{
            		sprintf(polecenie, "ALTER TABLE %s ALTER COLUMN %s TYPE VARCHAR(%d)",nazwa,tab[0][i],dozmiany[i]);
					doSQL(con,polecenie);
				}
			for(k=1;k<max;k++) //dodawanie rekordow z pliku
            {
            	sprintf(polecenie, "INSERT INTO %s VALUES (%s",nazwa,tab[k][0]);
            	for(i=1;i<=ileK;i++)
				{
					sprintf(kawalek,", %s",tab[k][i]);
					strcat(polecenie,kawalek);
				}
				strcat(polecenie,")");
				doSQL(con,polecenie);
			}
			printf("\n-----------------------------------------------------------\n");
			printf("Czy chcesz dodac rekord do tabeli %s (T lub N)?\n",nazwa);
			char odp[1];
   			char slowo[MAX];
   			char slowo2[MAX];
   			scanf("%s",&odp[0]); //getchar() oraz scanf do chara nie odapala sie
			while(((strcmp(odp,"t")==0) || (strcmp(odp,"T")==0))) //dodawanie do tabeli
			{
				sprintf(slowo,"%d",max);
				strcpy(tab[max][0],slowo);
				for(i=1;i<=ileK;i++)
				{
					printf("Podaj %s\n",tab[0][i]);
					scanf("%s",slowo);
					if(strcmp(slowo,"NULL")==0)
						strcpy(tab[max][i],slowo);
					else
					{
						sprintf(slowo2,"'%s'",slowo);
						strcpy(tab[max][i],slowo2);
					}
					if(strlen(slowo)>dozmiany[i])
					{
						dozmiany[i]=strlen(slowo);
						sprintf(polecenie, "ALTER TABLE %s ALTER COLUMN %s TYPE VARCHAR(%d)",nazwa,tab[0][i],dozmiany[i]);
						doSQL(con,polecenie);
					}
				}
				sprintf(polecenie, "INSERT INTO %s VALUES (%s",nazwa,tab[max][0]);
            	for(i=1;i<=ileK;i++)
				{
					sprintf(kawalek,", %s",tab[max][i]);
					strcat(polecenie,kawalek);
				}
				strcat(polecenie,")");
				doSQL(con,polecenie);
				max++;
				printf("\n-----------------------------------------------------------\n");
				printf("Czy chcesz dodac rekord do tabeli %s (T lub N)?\n",nazwa);
				temp=0;
				scanf("%s",&odp[0]);
			}
			sprintf(polecenie,"SELECT * FROM %s",nazwa);
			doSQL(con,polecenie);
			printf("\n-----------------------------------------------------------\n");
			if(argc>2)
			{
				HTMLprint(con,argc,argv);
			}
			else
				printf("Nic nie wydrukowano do html, za malo argumentow\n");
			fclose(dane);
		}
  	}
  	else
   		 printf("Polaczenie nieudane: %s\n", PQerrorMessage(con));
  	// w razie utraty po³±czenia wywo³anie 
  	// PQreset(myconnection);
 	// zamyka op³±czenie i nawi±zuje je raz jeszcze  
  	PQfinish(con);
	return EXIT_SUCCESS;
}
