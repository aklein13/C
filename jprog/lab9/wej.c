#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct {
  char nazwa[20];
  float cena;
  char kolor[16];
} przedmiot;

  char miejsce[20];
  char nazwa_wlasna[40];
  char trunek[16];
  int odleglosc;
  int ile_przed;
 przedmiot tab[10];
 
void czytanie()
{
	int i=0;
	FILE * czytaj = fopen("data.txt", "r");
    if (czytaj == NULL) {
        printf("Pusty plik\n");
    }
    fscanf(czytaj,"%s", nazwa_wlasna);
    fscanf(czytaj,"%s", miejsce);
    fscanf(czytaj,"%s", trunek);
    fscanf(czytaj,"%d", &odleglosc);
    fscanf(czytaj,"%d", &ile_przed);
    for(i=0;i<ile_przed;i++)
    {
		fscanf(czytaj, "%s %f %s", tab[i].nazwa, &tab[i].cena, tab[i].kolor);
	}
	fclose(czytaj);
}



int main () 
{
	int i;
	czytanie();
	printf("Jest %d \n",ile_przed);
	for(i=0;i<10;i++)
	{
		printf("%s %f %s\n",tab[i].nazwa, tab[i].cena, tab[i].kolor);
	}
  return 0;
}

