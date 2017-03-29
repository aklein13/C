#include <stdio.h>
#include <math.h>
// p- poczatek, r - koniec
#define MAX 1000

int n; //rozmiar tablicy

void bubble(int tab[], int p, int r)
{
	int i, tmp, j;
	for(i=p;i<r;i++)
	{
		for(j=p;j<r;j++)
		{
			if(tab[j]>tab[j+1])
			{
				tmp=tab[j];
				tab[j]=tab[j+1];
				tab[j+1]=tmp;
			}
		}
	}
}

int czytanie(int tab[])
{
	int i=1;
	FILE * dane = fopen("dane.txt", "r");
    if (dane == NULL) 
	{
        printf("Blad odczytu pliku! Potrzeba pliku dane.txt z liczbami\n");
        return 0;
    }
    while(fscanf(dane,"%d",&tab[i])==1)
	{
		i++;
	}
	fclose(dane);
	return i;
}

void zapis(int tab[])
{
	int i;
	FILE * dane = fopen("out.txt", "w+");
    for(i=1;i<=n;i++)
    {
		fprintf(dane,"%d\n",tab[i]);
	}
	printf("\nZapisano dane do pliku out.txt\n");
	fclose(dane);
}

int main()
{
	int i;
	int tab[MAX];
	n=czytanie(tab);
	n--;
	printf("Wczytano %d:\n",n);
	for(i=1;i<n+1;i++)
		printf("%d ",tab[i]);
	printf("\n");
	bubble(tab,0,n);
	printf("\nPosortowane:\n");
	for(i=1;i<n+1;i++)
		printf("%d ",tab[i]);
	zapis(tab);
	return 0;
}
