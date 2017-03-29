#include <stdlib.h>
#include <stdio.h>
//#include <libpq-fe.h>
#include <string.h>
#include <unistd.h>
// LOL 3 wymiarowe tablice <333
char tab[50][50][50];

void czytanie()
{
	int i=0;
	int j=0;
	int k=0;
	int max=0;
	char temp;
	char koniec='\n';
	char next=';';
	FILE * dane = fopen("osoba.csv", "r");
    if (dane == NULL) 
	{
        printf("Blad odczytu pliku! Potrzeba pliku nazwa.csv z danymi\n");
    }
    while(fscanf(dane,"%c",&temp)==1)
	{
		if (temp==next) 
		{
			if(tab[k][i][j-1]!=0 && k!=0 && i!=0)
				tab[k][i][j]=(char)39;
			j=0;
			if(tab[k][i][j]==0)
				strcpy(tab[k][i],"NULL");
			i++;
		}
		else if (temp==koniec) 
		{
			if(tab[k][i][j-1]!=0 && k!=0 && i!=0)
				tab[k][i][j]=(char)39;
			j=0;
			if(tab[k][i][j]==0)
				strcpy(tab[k][i],"NULL");
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
	fclose(dane);
}

void wyswietl()
{
	int i=0;
	int j=0;
	int k=0;
	while(tab[k][i][j]!=0)
	{
		while(tab[k][i][j]!=0)
		{
			while(tab[k][i][j]!=0)
			{
				printf("%c",tab[k][i][j]);
				j++;
			}
			j=0;
			i++;
			printf(" ");
		}
		j=0;
		i=0;
		k++;
		printf("\n");
	}
}

int main()
{
	czytanie();
	printf("Czy cos dodac?\n");
	char odp;
	char temp[50];
	char temp2[50];
	int i;
	int max=12;
	while((odp = getchar()) == 't' || (odp == 'T'))
	{
		sprintf(temp,"%d",max);
		strcpy(tab[max][0],temp);
		for(i=1;i<6;i++)
		{
			printf("Podaj %s\n",tab[0][i]);
			scanf("%s",temp);
			if(strcmp(temp,"NULL")==0)
				strcpy(tab[max][i],temp);
			else
			{
				sprintf(temp2,"'%s'",temp);
				strcpy(tab[max][i],temp2);
			}
		}
		max++;
		printf("\nCzy cos dodac?\n");
	}
	wyswietl();
    return 0;
}
