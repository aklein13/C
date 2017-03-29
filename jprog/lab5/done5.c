#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
	char nazwa[20];
	char miasto[20];
	int ile_przed;
	float obroty;
} sklep;

sklep tab[3];
int czy=4;

sklep dodaj(char nazwaa[20], int nowe)
{
	int i;
	for(i=0; i<3; i++)
	{
		if(strcmp(nazwaa, tab[i].nazwa) == 0)
		czy=i;
	}
	
	sklep zm;
	strcpy(zm.nazwa,tab[czy].nazwa);
	strcpy(zm.miasto,tab[czy].miasto);
	zm.ile_przed=tab[czy].ile_przed+nowe;
	zm.obroty=tab[czy].obroty;
	return zm;
}

int main()
{
int i, nowe;
char nazwaa[20];
sklep n;
for(i=0;i<3;i++)
{
printf("Podaj nazwe, miasto, ilosc_przed oraz obroty sklepu %d :\n",i+1);
scanf("%s %s %d %f", tab[i].nazwa, tab[i].miasto, &tab[i].ile_przed, &tab[i].obroty);
}
printf("\n");
printf("Wpisane sklepy (nazwa,miasto,ile_przed,obroty):\n");
for(i=0; i<3; i++)
{
	printf("%s %s %d %f\n",tab[i].nazwa, tab[i].miasto, tab[i].ile_przed, tab[i].obroty);
}

printf("\nPodaj nazwe sklepu oraz ilosc przedmiotow do dodania:\n");
scanf("%s %d", nazwaa, &nowe);
n=dodaj(nazwaa, nowe);
printf("\nZmieniony sklep (nazwa,miasto,ile_przed,obroty):\n%s %s %d %f",n.nazwa, n.miasto, n.ile_przed, n.obroty);
return 0;
}
