#include <stdio.h>
#include <math.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100
#define DL 7

//int n;
char tab[MAX][MAX];
char bat[MAX][MAX];

void csort(int p, int n)	//p-pozycja
{
    int k=123;	//zakres
    int C[k];	//pom
    int i,j,l,miejsce;
    for(i=0;i<k;i++)
        C[i]=0;
    for(i=0;i<n;i++)
        C[(int)tab[i][p]]++;
    for(i=1;i<k;i++)
        C[i]=C[i]+C[i-1];
        
    for(i=n;i>=0;i--)
	{
		miejsce=C[(int)tab[i][p]]-1;
        for(j=0;j<DL;j++)
        	bat[miejsce][j]=tab[i][j];
        C[(int)tab[i][p]]--;
    }
    for(j=0;j<n;j++)
    {
       	for(l=0;l<p;l++)
       		printf("%c",bat[j][l]);
       	printf("|");
       	printf("%c",bat[j][l]);
       	printf("|");
       	for(l=p+1;l<DL;l++)
       		printf("%c",bat[j][l]);
       	printf("\n");
    }
}
	
void radix(int n)
{
    int i,j;
    for(i=DL-1;i>=0;i--)
	{
        csort(i,n);
        for(j=0;j<n;j++)
        	memcpy(tab+j, bat+j, DL);
        printf("Gotowe dla pozycji %d\n\n",i);
    }
}
	
void wyswietl(int n)
{
	int i,j;
	for(i=0;i<n;i++)
	{
		for(j=0;j<DL;j++)
		{
			printf("%c",tab[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}
	
int czytanie()
{
	int i,j;
	i=0;
	char temp;
	FILE * dane = fopen("input.txt", "r");
    if (dane == NULL) 
	{
        printf("Blad odczytu pliku! Potrzeba pliku input.txt z danymi\n");
        return 0;
    }
    while(fscanf(dane,"%c",&temp)==1)
	{
		tab[i][0]=temp;
		for(j=1;j<DL;j++)
		{
			fscanf(dane,"%c",&tab[i][j]);
		}
		fscanf(dane,"%c",&temp);
		i++;
	}
	fclose(dane);
	printf("Wczytano:\n");
	wyswietl(i);
	return i;
}

int main()
{
	int i;
	int n;
	n=czytanie();
	radix(n);
	printf("Posortowano:\n");
	wyswietl(n);
	return 0;
}
