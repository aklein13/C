#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int m=3500;
int kolizje = 0;
int numbers = 0;
int A[3500] = { 0 }; //outpot

int hash(int k)
{
    return k % m;
}

int getSize(char *name)
{
    int l = 0;
    int k;
    char tmp[25];
    FILE *f = fopen(name, "r");
    do
	{
        k = fscanf(f, "%s", tmp);
        l++;
    }while(k == 1);
    return l;
}

void insert(int T[], int k)
{
    if(T[hash(k)] > 0)
	{
        A[hash(k)]++;
    } else 
	{
        T[hash(k)] = k;
        A[hash(k)]++;
    }
}

void show(int T[])
{
    int i;
    for(i = 0; i < m; i++)
        if(T[i] > 0)
            printf("T[%i] = %i \n", i, T[i]);
}

int conv(const char * word)
{
    int n = 0;
    int l = strlen(word);
    int i;
    for(i = 0; i < l; i+=2)
	{
        n += ((int)word[i] * 11) ^ (int)word[i+1];
    }
    return n;
}

void load(int T[], char *name)
{
    int i;
    int size = getSize(name) - 1;
    FILE *f = fopen(name, "r");
    //printf("%i", size);
    char tmp[20];
    for(i = 0; i < size; i++)
	{
            fscanf(f, "%s", tmp);
            T[i] = conv(tmp); //zamiana na liczbe
    }
    printf("Wczytano %s\n",name);
}


void zlicz()
{
    int i = 0;
    int zera = 0;
    int niezera = 0;
    int ilosc = 0;
    int max = 0;
    for(i = 0; i < m; i++)
	{
        if(A[i] == 0)
		{
            zera++;
        }
        if(A[i] > 0)
		{
            niezera += A[i];
            ilosc++;
        }
        max = ((A[i] > max) ? (A[i]) : (max));
    }
    printf("\n");
    printf("Ilosc zerowych pozycji %d \n", zera); //bezkolizyjne klucze
    printf("Maksymalna wartosc kolizji W: %d \n", max); //najw kolizji
    printf("Srednia wartosc pozycji niezerowych: %lf \n", (float)niezera/(float)ilosc);
}

int main()
{
    int J[3500] = { 0 };
    int i;
    for(i = 0; i < m; i++)
    	A[i] = 0 ;
    int k = getSize("3700.txt");
    int T[k];
    load(T, "3700.txt");
    printf("\nDla 3500\n");
    for(i = 0; i < 2*m; i++)
	{
        insert(J, T[i]);
    }
    //show(A);
    zlicz();
    for(i = 0; i < m; i++)
    	A[i] = 0 ;
    printf("\nDla 2500\n");
    m=2500;
    for(i = 0; i < 2*m; i++)
	{
        insert(J, T[i]);
    }
    zlicz();
    for(i = 0; i < m; i++)
    	A[i] = 0 ;
    printf("\nDla 1500\n");
    m=1500;
    for(i = 0; i < 2*m; i++)
	{
        insert(J, T[i]);
    }
    zlicz();
    return 0;
}
