#include <stdio.h>
#include <math.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define MAX 20100
#define MLD 1000000000.0 // 10 ** 9

char tab[MAX][MAX];
char bat[MAX][MAX];
int max=0;

void csort(int p, int n)	//p-pozycja
{
    int k=123;	//zakres
    int C[k];	//pom
    //printf("%d%d",p,n);
    int i,j,miejsce;
    //int l;
    for(i=0;i<k;i++)
        C[i]=0;
    for(i=0;i<n;i++)
        C[(int)tab[i][p]]++;
    for(i=1;i<k;i++)
        C[i]=C[i]+C[i-1];
    for(i=n-1;i>=0;i--)
	{
		miejsce=C[(int)tab[i][p]]-1;
    	for(j=0;j<max;j++)
      		bat[miejsce][j]=tab[i][j];  	
	    C[(int)tab[i][p]]--;
    }
    /*for(j=0;j<n;j++)
    {
       	for(l=0;l<p;l++)
       		printf("%c",bat[j][l]);
       	printf("|");
       	printf("%c",bat[j][l]);
       	printf("|");
       	for(l=p+1;l<max;l++)
       		printf("%c",bat[j][l]);
       	printf("\n");
    }*/
}
	
void radix(int n)
{
    int i,j;
    for(i=max-1;i>=0;i--)
	{
        csort(i,n);
        for(j=0;j<n;j++)
        	memcpy(tab+j, bat+j, max);
        //printf("Gotowe dla pozycji %d\n\n",i);
    }
}
	
void wyswietl(int n)
{
	int i,j;
	for(i=0;i<n+1;i++)
	{
		for(j=0;j<max;j++)
		{
			printf("%c",tab[i][j]);
		}
		printf("\n");
	}
}

int czytanie()
{
	int i=0;
	int j=0;
	char temp;
	char koniec='\n';
	FILE * dane = fopen("naz.txt", "r");
    if (dane == NULL) 
	{
        printf("Blad odczytu pliku! Potrzeba pliku naz.txt z danymi\n");
        return 0;
    }
    while(fscanf(dane,"%c",&temp)==1)
	{
		if((int)temp>=48 && (int)temp<=57) {}
		else if ((int)temp==32) {}
		else if(koniec!=temp)
		{
			tab[i][j]=temp;
			j++;
		}
		else
		{
			if(j>max)
				max=j;
			j=0;
			i++;
		}
	}
	i++;
	fclose(dane);
	//printf("Wczytano\n");
	//wyswietl(i);
	return i;
}

void zapis(int n)
{
	int i,j;
	FILE * dane = fopen("out.txt", "w+");
    for(i=1;i<n;i++)//1
    {
		for(j=0;j<max;j++)
			if(tab[i][j]!=0)
				fprintf(dane,"%c",tab[i][j]);
		fprintf(dane,"\n");
	}
	printf("\nZapisano dane do pliku out.txt\n");
	fclose(dane);
}

int partition(int p, int r)
{
	int i,j,l;
	char temp[max];
	char ttt[max];
	char x[max];
	strcpy(x,tab[r]);
	i=p-1;
	for(j=p; j<=r; j++)
	{
		if (strcmp(tab[j],x)<=0)	//tab[j] <= x
		{
			i++;
			strcpy(temp, tab[i]);
			strcpy(ttt, tab[j]);
			for(l=0;l<max;l++)
				tab[j][l]=0;
			for(l=0;l<max;l++)
				tab[i][l]=0;
			strcpy(tab[i],ttt);
			strcpy(tab[j],temp);
		}
	}
	if (i<r) return i;
	else return i-1;
}

void quicksort(int p, int r)
{
	int q;
	if (p<r)
	{
		q=partition(p,r);
		quicksort(p,q);
		quicksort(q+1,r);
	}
}

int main()
{
	int n,i,j;
	struct timespec tp0, tp1, tp2, tp3;
	double czas1,czas2;
	n=czytanie();
	clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &tp0);
	radix(n); //radix & csort
	clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &tp1);
	czas1 = (tp1.tv_sec + tp1.tv_nsec/MLD) - (tp0.tv_sec + tp0.tv_nsec/MLD);
	//wyswietl(n); //ew wyswietlanie
	//zapis(n);	//ew zapis do pliku txt
	printf("Wczytano %d slow\n\n",n);
	printf("Posortowano Radix, zajelo: %lf\n",czas1);
	for(i=0;i<n;i++)	//zerowanie
		for(j=0;j<max;j++)
			tab[i][j]=0;
	n=czytanie();
	clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &tp2);
	quicksort(0,n-1); //quick sort
	clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &tp3);
	czas2 = (tp3.tv_sec + tp3.tv_nsec/MLD) - (tp2.tv_sec + tp2.tv_nsec/MLD);
	printf("Posortowano Quicksort, zajelo: %lf\n\n",czas2);
	printf("------------------------\n");
	printf("| Quicksort |   Radix  |\n");
	printf("|----------------------|\n");
	printf("|  %lf | %lf |\n",czas2,czas1);
	printf("------------------------\n\n");
	if(czas2<czas1)
		printf("Quicksort byl szybszy o %lf\n",czas1-czas2);
	else if(czas1<czas2)
		printf("Radix byl szybszy o %lf\n",czas2-czas1);
	else
		printf("Remis\n");
	zapis(n);
	return 0;
}
