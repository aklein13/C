#include <stdio.h>
#include <math.h>

#define MAX 1000

int size; //heapsize
int n; //rozmiar tablicy

int syn(int i)
{
	if (i!=0)	return 2*i;
	else	return 1;
}

void heapify(int tab[], int i)
{
	int max, temp;
	int l=syn(i);
	int r=l+1; //2*i+1
	if (l<=size && tab[l]>tab[i])
		max=l;
	else 
		max=i;
	if (r<=size && tab[r]>tab[max])
		max=r;
	if (max!=i)
	{
		temp=tab[max];
		tab[max]=tab[i];
		tab[i]=temp;
		heapify(tab,max);
	}
}

void heapbuild(int tab[])
{
	int i;
	size=n;
	for (i=floor(n/2);i>0;i--)
		heapify(tab,i);
	printf("Kopiec:\n");
	for(i=1;i<n+1;i++)
		printf("%d ",tab[i]);
}

void heapsort(int tab[])
{
	int i, temp;
	size=n;
	heapbuild(tab);
	for (i=n;i>1;i--)
	{
		temp=tab[i];
		tab[i]=tab[1];
		tab[1]=temp;
		size--;
		heapify(tab,1);
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
	size=n;
	printf("Wczytano %d:\n",n);
	for(i=1;i<n+1;i++)
		printf("%d ",tab[i]);
	printf("\n");
	heapsort(tab);
	printf("\nPosortowane:\n");
	for(i=1;i<n+1;i++)
		printf("%d ",tab[i]);
	zapis(tab);
	return 0;
}
