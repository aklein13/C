#include <stdio.h>
#include <math.h>
//p to poczatek, r to koniec
#define MAX 1000

int n;

int partition(int tab[], int p, int r)
{
	int x,i,j,temp;
	x=tab[r];
	i=p-1;
	for(j=p; j<=r; j++)
	{
		if (tab[j] <= x)
		{
			i++;
			temp=tab[i];
			tab[i]=tab[j];
			tab[j]=temp;
		}
	}
	if (i<r) return i;
	else return i-1;
}

void quicksort(int tab[], int p, int r)
{
	if (p<r)
	{
		int q;
		q=partition(tab,p,r);
		quicksort(tab,p,q);
		quicksort(tab,q+1,r);
	}
}
	
int czytanie(int tab[])
{
	int i=1;
	FILE * dane = fopen("input.txt", "r");
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
	printf("Quicksort\nWczytano %d:\n",n);
	for(i=1;i<n+1;i++)
		printf("%d ",tab[i]);
	printf("\n");
	quicksort(tab,0,n);
	printf("\nPosortowane:\n");
	for(i=1;i<n+1;i++)
		printf("%d ",tab[i]);
	zapis(tab);
	
	return 0;
}
