#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>

#define MAX 18

typedef struct przedmiot 
{
    char name[MAX];
    struct przedmiot* dalej;
}* lista;

//=======================================================

lista dodaj(char nazw[MAX], lista my_list) 
{
   lista pom;
   pom = (struct przedmiot*) malloc(sizeof(struct przedmiot));
   strcpy(pom->name,nazw);
   pom->dalej=my_list;
   return pom;
}

//=======================================================

lista  katalog(lista my_list) 
{
 	char nazw[MAX];
 	int i=0;
 	FILE* baza = fopen("dane.txt","r");
  	if (baza == NULL) 
 	 	printf("\n Brak pliku dane.txt\n\n");
	while(fscanf(baza,"%s",nazw)==1)
 	{
 	   my_list=dodaj(nazw,my_list);
 	   i++;
  	}
  	fclose(baza);
  	return my_list;
}

lista kasuj(lista my_list)
{
	my_list=NULL;
	return my_list;
}
//=======================================================  

lista szukaj(lista my_list, char nazwa[MAX])
{
	int jest=0;
	lista pom = my_list;
	while(pom != NULL)
	{
		if (strcmp(pom->name,nazwa)==0)
		{
			printf("Usunieto '%s'\n",nazwa);
			return pom;
		}
		pom=pom->dalej;
	}
	printf("Nie znaleziono: %s . Nie zrobie nic\n\n",nazwa);
	return NULL;
}
//=======================================================

lista odwroc(lista my_list)
{
  	lista pom = NULL;
 	char slowo[MAX];
 	while (my_list!=NULL) 
 	{
  	 	strcpy(slowo,my_list->name); 
		my_list=my_list->dalej;
 	   	pom=dodaj(slowo,pom);
 	}
 	return pom;
}

lista usun(lista my_list, char nazwa[MAX])
{
	int i=0;
	lista pom=my_list;
	lista nowa=NULL;
	nowa=szukaj(my_list,nazwa);
	if(nowa!=NULL)
	{
		nowa=kasuj(nowa);
		while(pom!=NULL && i==0)
		{
			if(strcmp(pom->name,nazwa)!=0)
				nowa=dodaj(pom->name,nowa);
			else
				{i++;}
			pom=pom->dalej;
		}
		while(pom!=NULL)
		{
			nowa=dodaj(pom->name,nowa);
			pom=pom->dalej;
		}
		return nowa;
	}
	else
		return pom;
}

int n_usun(lista my_list, char nazwa[MAX])
{
	int i=0;
	lista pom=my_list;
	lista nowa=NULL;
	while(pom!=NULL)
	{
		if(strcmp(pom->name,nazwa)!=0)
				nowa=dodaj(pom->name,nowa);
		else
			{i++;}
		pom=pom->dalej;
	}
	return i;
}

lista bezp(lista my_list)
{
	int j=0;
	int ile,i,samo;
	char tab[MAX][MAX];
	int bat[MAX];
	for(i=0;i<MAX;i++)
		bat[i]=0;
	lista temp=my_list;
	lista pom;
	lista wynik;
	while(temp!=NULL)
	{
		pom=my_list;
		ile=n_usun(pom,temp->name);
		if(ile!=1)
		{
			samo=0;
			for(i=0;i<j;i++)
			{
				if(strcmp(tab[i],temp->name)==0)
				{
					samo=1;
					bat[i]++;
				}
			}
			if(samo==0)
			{
				strcpy(tab[j],temp->name);
				bat[j]++;
				printf("%s\n",tab[j]);
				j++;
			}
			else{}
		}
		temp=temp->dalej;
	}
	wynik=my_list;
	for(i=0;i<j;i++)
	{
		wynik=usun(wynik,tab[i]);
		while(bat[i]>2)
		{
			wynik=usun(wynik,tab[i]);
			bat[i]--;
		}
	}
	return wynik;
}

void druk(lista my_list) 
{
	lista wynik = my_list;
	while(wynik!=NULL)
	{
		printf("%s \n",wynik->name);
		wynik=wynik->dalej;
	}
}

lista scal(lista my_list, lista bez_list)
{
	int i=0;
	lista pom=my_list;
	lista temp=bez_list;
	lista nowa=NULL;
	printf("\nScalanie my_list i bez_list\n");
	while(pom!=NULL)
	{
		nowa=dodaj(pom->name,nowa);
		pom=pom->dalej;
	}
	while(temp!=NULL)
	{
		nowa=dodaj(temp->name,nowa);
		temp=temp->dalej;
	}
	printf("Kasowanie my_list\n");
	my_list=kasuj(my_list);
	printf("Kasowanie bez_list\n");
	bez_list=kasuj(bez_list);
	return nowa;
}

int main()
{
	char test[20]="doodane";
	lista my_list=NULL;
	lista bez_list=NULL;
	lista sc_list=NULL;
	my_list=katalog(my_list);
	printf("Wpisano do my_list:\n");
	druk(odwroc(my_list));
	printf("\nPodaj element do usuniecia na liscie\n");
	scanf("%s",test);
	my_list=usun(my_list,test);
	printf("\nLista my_list:\n");
	druk(my_list);
	printf("\nPowtarzajace sie wyrazy w my_list:\n");
	bez_list=bezp(my_list);
	printf("\nLista bez_list:\n");
	druk(bez_list);
	sc_list=scal(bez_list,odwroc(my_list));
	printf("\nList sc_list (scalone my_list i bez_list):\n");
	druk(sc_list);
	my_list=kasuj(my_list);
	printf("\nLista my_list:\n");
	druk(my_list);	//powinno byc puste
	bez_list=kasuj(bez_list);
	printf("\nLista bez_list:\n");
	druk(bez_list);	//powinno byc puste
	return 0;
}
