#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
	char tytul_gry[20];
	float cena;
	int id;
} gra;

gra tabgier[3];

void obnizka(int id, int procent)
{
	double pro;
	pro=procent;
	pro=pro/100;
	tabgier[id].cena=tabgier[id].cena*(1-pro);
}

int main()
{
int i, id, procent;

for(i=0;i<3;i++)
{
printf("Podaj tytul oraz cene gry %d :\n",i+1);
scanf("%s %f", tabgier[i].tytul_gry, &tabgier[i].cena);
tabgier[i].id = i;
}

printf("Wpisane gry:\n");
for(i=0; i<3; i++)
{
	printf("%d %s %f\n",tabgier[i].id, tabgier[i].tytul_gry, tabgier[i].cena);
}

printf("\nPodaj id gry oraz procent obnizki:\n");
scanf("%d %d", &id, &procent);
obnizka(id, procent);
printf("Done. Cena gry %s zostala zmiejszona do: %f",tabgier[id].tytul_gry , tabgier[id].cena);
return 0;
}
