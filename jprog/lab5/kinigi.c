#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
	char nazwa[20];
	int ilosc_stron;
	int numer;
} book;

book ksiazki[4];

void zmiana(int numer, char nowy_tytul[20])
{
	strcpy(ksiazki[numer].nazwa, nowy_tytul);
}

int main()
{
	int i, id;
	char nowa_nazwa[20];
	for(i=0; i<4; i++)
	{
		printf("Podaj nazwe oraz ilosc stron ksiazki %d:\n", i+1);
		scanf("%s %d", ksiazki[i].nazwa, &ksiazki[i].ilosc_stron);
		ksiazki[i].numer = i;
	}
	
	printf("Wpisane ksiazki:\n");
	for(i=0; i<4; i++)
	{
		printf("%d %s %d\n", ksiazki[i].numer, ksiazki[i].nazwa, ksiazki[i].ilosc_stron);
	}
	
	printf("Podaj id oraz nowa nazwe ksiazki:\n");
	scanf("%d %s", &id, &nowa_nazwa);
	zmiana(id, nowa_nazwa);
	
	printf("Nowa nazwa ksiazki nr %d to %s\n", id, ksiazki[id].nazwa);
	return 0;
}
