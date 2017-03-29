#include <stdio.h>
#include <string.h>

int main()
{
	FILE *plik=fopen("dane.txt","a");
	int i;
	int temp;

	struct osoba
	{
		char imie[30];
		char nazwisko[40];
		int wiek;
	};
	struct osoba o[5];
	
	for(i=0;i<5;i++)
	{
		temp=i;
		printf("Podaj dane %d osoby:\n",i);
		scanf("%s",o[i].imie);
		scanf("%s",o[i].nazwisko);
		scanf("%d",&o[i].wiek);
		if (o[i].wiek < 0)
		{
			temp=i;
			i=6;
		}
	}
	for(i=0;i<temp;i++)
	{
		printf("%d. %s %s %d\n",i,o[i].imie, o[i].nazwisko, o[i].wiek);
		fprintf(plik,"%d. %s %s %d\n",i,o[i].imie, o[i].nazwisko, o[i].wiek);
	}
	return 0;
}
