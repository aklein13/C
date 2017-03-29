#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define m 1100
int kolizje = 0;
int numbers = 0;
int A[m] = { 0 }; //outpot
// W+OL - wstaw + otwarte liniowe
struct osoba
{
    char nazwisko[25];
    int ilosc;
};

int hashFunc1(int k)
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

int hashFuncA(int k, int i)
{
    return (hashFunc1(k) + i) % m;
}

int insert(struct osoba *T[], int k, struct osoba* person)
{
	int i = 0 ;
    numbers++;
    int j;
    do
	{
        j = hashFuncA(k, i);
        if(T[j] == (void*)0 || T[j] == (void*)-1)
		{
            T[j] = person;
            return 1;
        } else 
		{
            A[j]++;
            kolizje++;
            i++;
        }
    }while(i < m);
    return 0;
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

void load(struct osoba T[], char *name)
{
    int i;
    int size = getSize(name) - 1;
    FILE *f = fopen(name, "r");
    char tmp[30];
    for(i = 0; i < size; i++)
	{
            fscanf(f, "%i", &T[i].ilosc);
            fscanf(f, "%s", tmp);
            strcpy(T[i].nazwisko, tmp);
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
    printf("Wielkosc tablicy: %d\n", m);
    printf("Ilosc zer w tablicy: %d \n", zera);
    printf("Maksymalna ilosc kolizji: %d \n", max);
    printf("Srednia ilosc kolizji: %lf \n", (double)niezera/(double)ilosc);
}

int main()
{
    int i;
    for(i = 0; i < m; i++)
    	A[i] = 0 ;
    struct osoba *J[m] = { 0 };
    int k = getSize("nazw.txt");
    struct osoba T[k];
    int liczba;
    load(T, "nazw.txt");/*
    for(i = 0; i < m; i++)
	{
        liczba = conv(T[i].nazwisko);
        insert(J, liczba, &T[i]);
    }
    zlicz();*/
    //show(A);
    printf("\nDla tablicy 50 wypelnienia:\n");
    for(i = 0; i < m; i++)
    	A[i] = 0 ;
    for(i = 0; i < m*0.5; i++)
    	A[i] = 1 ;
    for(i = 0; i < 5*m/100; i++)
	{
        int liczba = conv(T[i].nazwisko);
        insert(J, liczba, &T[i]);
    }
    zlicz();
    printf("\nDla tablicy 70 wypelnienia:\n");
    for(i = 0; i < m; i++)
    	A[i] = 0 ;
    for(i = 0; i < m*0.7; i++)
    	A[i] = 1 ;
    for(i = 0; i < 5*m/100; i++)
	{
        int liczba = conv(T[i].nazwisko);
        insert(J, liczba, &T[i]);
    }
    zlicz();
    printf("\nDla tablicy 90 wypelnienia:\n");
    for(i = 0; i < m; i++)
    	A[i] = 0 ;
    for(i = 0; i < m*0.9; i++)
    	A[i] = 1 ;
    for(i = 0; i < 5*m/100; i++)
	{
        int liczba = conv(T[i].nazwisko);
        insert(J, liczba, &T[i]);
    }
    zlicz();
    return 0;
}
