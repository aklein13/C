#include <stdio.h>
#include <math.h>
#include <time.h>
#include <stdlib.h>
//p to poczatek, r to koniec
#define MAX 99999
#define MLD 1000000000.0 // 10 ** 9

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

void quick_bubble(int tab[], int p, int r, int c)
{
	if (p<r)
	{
		if((r-p+1)<c)
			bubble(tab,p,r);
		else
		{
			int q;
			q=partition(tab,p,r);
			quick_bubble(tab,p,q,c);
			quick_bubble(tab,q+1,r,c);
		}
	}
}
	
int czytanie(int tab[])
{
	int i=0;
	FILE * dane = fopen("input.txt", "r");
    if (dane == NULL) 
	{
        printf("Blad odczytu pliku! Potrzeba pliku input.txt z liczbami\n");
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
    for(i=0;i<n;i++)
    {
		fprintf(dane,"%d\n",tab[i]);
	}
	printf("\nZapisano dane do pliku out.txt\n");
	fclose(dane);
}

void generate(int rodzaj, int n)
{
	FILE * input = fopen("input.txt", "w");
	int x, i;
	if (rodzaj==1)
	{
		srand(time(NULL));
		for(i=0;i<n;i++)
		{
			x = rand()%2500;
			fprintf(input,"%d\n",x);
		}
	}
	else if(rodzaj==3) //rosnace
	{
		for(i=0;i<n;i++)
			{
				fprintf(input,"%d\n",i);
			}	
	}
	else if(rodzaj==2) //malejace
	{
		for(i=n;i>0;i--)
			{
				fprintf(input,"%d\n",i-1);
			}
	}
	fclose(input);
}

int main()
{
	
	int i,c,koniec;
	struct timespec tp0, tp1, tp2, tp3;
	double czas1, czas2;
	int tab[MAX];
	n=100;
	koniec=1;
	czas1=0;
	czas2=0;
	printf("\tDane losowe:\n");
	printf(" Ilosc  | QuickSort| Bubble_QuickSort\n");
	generate(koniec,n);
	czytanie(tab);
	while(koniec!=3)
	{
		c=log(n);
		for(i=0;i<n;i++)
		{
			generate(koniec,n);
			czytanie(tab);
			clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &tp0);
			quicksort(tab,0,n);
			clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &tp1);
			czas1 = czas1 +( (tp1.tv_sec + tp1.tv_nsec/MLD) - (tp0.tv_sec + tp0.tv_nsec/MLD));
			generate(koniec,n);
			czytanie(tab);
			clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &tp2);
			quick_bubble(tab,0,n,c);
			clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &tp3);
			czas2 = czas2 + ( (tp3.tv_sec + tp3.tv_nsec/MLD) - (tp2.tv_sec + tp2.tv_nsec/MLD));
		}
		printf("n = %d | %lf |\t%lf\n",n,czas1/n,czas2/n);
		czas1=0;
		czas2=0;
		n=500;
		c=log(n);
		for(i=0;i<n;i++)
		{
			generate(koniec,n);
			czytanie(tab);
			clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &tp0);
			quicksort(tab,0,n);
			clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &tp1);
			czas1 = czas1 +( (tp1.tv_sec + tp1.tv_nsec/MLD) - (tp0.tv_sec + tp0.tv_nsec/MLD));
			generate(koniec,n);
			czytanie(tab);
			clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &tp2);
			quick_bubble(tab,0,n,c);
			clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &tp3);
			czas2 = czas2 + ( (tp3.tv_sec + tp3.tv_nsec/MLD) - (tp2.tv_sec + tp2.tv_nsec/MLD));
		}
		printf("n = %d | %lf |\t%lf\n",n,czas1/n,czas2/n);
		n=1000;
		czas1=0;
		czas2=0;
		c=log(n);
		for(i=0;i<n;i++)
		{
			generate(koniec,n);
			czytanie(tab);
			clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &tp0);
			quicksort(tab,0,n);
			clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &tp1);
			czas1 = czas1 +( (tp1.tv_sec + tp1.tv_nsec/MLD) - (tp0.tv_sec + tp0.tv_nsec/MLD));
			generate(koniec,n);
			czytanie(tab);
			clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &tp2);
			quick_bubble(tab,0,n,c);
			clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &tp3);
			czas2 = czas2 + ( (tp3.tv_sec + tp3.tv_nsec/MLD) - (tp2.tv_sec + tp2.tv_nsec/MLD));
		}
		printf("n = %d| %lf |\t%lf\n",n,czas1/n,czas2/n);
		n=2500;
		czas1=0;
		czas2=0;
		c=log(n);
		for(i=0;i<n;i++)
		{
			generate(koniec,n);
			czytanie(tab);
			clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &tp0);
			quicksort(tab,0,n);
			clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &tp1);
			czas1 = czas1 +( (tp1.tv_sec + tp1.tv_nsec/MLD) - (tp0.tv_sec + tp0.tv_nsec/MLD));
			generate(koniec,n);
			czytanie(tab);
			clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &tp2);
			quick_bubble(tab,0,n,c);
			clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &tp3);
			czas2 = czas2 + ( (tp3.tv_sec + tp3.tv_nsec/MLD) - (tp2.tv_sec + tp2.tv_nsec/MLD));
		}
		printf("n = %d| %lf |\t%lf\n",n,czas1/n,czas2/n);
		koniec++;
		czas1=0;
		czas2=0;
		if(koniec==2)
		{
			printf("\n\tDane malejace:\n");
			n=100;
		}
	}
	zapis(tab);
	return 0;
}
