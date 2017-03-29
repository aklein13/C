#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>

#define MAX 99
//tab double, bo 0,5 znaczy ze jest pusto
double tab[MAX];
int ile=0;
int maxp=0;

void wstaw(int n)
{
	int i;
	i=0;
	int juz=0;
	while(i<MAX && juz==0)
	{
		if(tab[i]==0.5)
		{
				tab[i]=n;
				juz++;
				if(maxp<i)
					maxp=i;
				printf("Wczytano %d na %d pozycji\n",n,i);
		}
		else if(n<=tab[i])
		{
			i=(i*2)+1; //idzie na lewo
		}
		else if(n>tab[i])
		{
			i=(i+1)*2; //idzie na prawo
		}
		
	}
}

int szukaj(int n) //szukanie wersja stara, gorsza
{
	int i;
	int jest=0;
	for(i=0; i<=maxp && jest==0; i++)
	{
		if(tab[i]==n)
		{
			if(i==0)
				jest=MAX+1;
			else
				jest=i;
		}
	}
	if(jest==0)
		return 0;
	else
	{
		return jest;
	}
}

int szukaj2(int n)
{
	int i=0;
	int jest=0;
	while(jest==0 && i<=maxp)
	{
		if(tab[i]==n)
		{
			if(i==0)
				jest=MAX+1;
			else
				jest=i;
		}
		else if(n<=tab[i])
		{
			i=(i*2)+1; //idzie na lewo
		}
		else if(n>tab[i])
		{
			i=(i+1)*2; //idzie na prawo
		}
	}
	if(jest==0)
		return 0;
	else
	{
		return jest;
	}
}

void drukuj()
{
	int i=0;
	int temp=ile;
	double kopia[MAX];
	for(i=0;i<MAX;i++)
		kopia[i]=tab[i];
	i=0;
	printf("\n\nDrukowanie drzewa (in-order)\n");
	while(temp>0)
	{
		if(kopia[i*2+1]==0.5)
		{
			if(kopia[i]==0.5)
				i=(i+1)*2;
			else
			{
				printf("%.0lf ",kopia[i]);
				temp--;
				kopia[i]=0.5;
				if(kopia[(i+1)*2]==0.5)
					i=0;
				else
					i=(i+1)*2;
			}
		}
		else
		{
			i=i*2+1;
		}
	}
}

void usun(int n)
{
	int i=szukaj2(n);
	if(i!=0)
	{
		if(i==MAX+1)
			i=0;
			if(tab[(i*2)+1]==0.5 && tab[(i+1)*2]==0.5) //brak synow
			{
				tab[i]=0.5;
			}
			else if(tab[(i*2)+1]==0.5 && tab[(i+1)*2]!=0.5) //prawy syn tylko
			{
				tab[i]=tab[(i+1)*2];
				tab[(i+1)*2]=0.5;
			}
			else if(tab[(i*2)+1]!=0.5 && tab[(i+1)*2]==0.5) //lewy syn tylko
			{
				tab[i]=tab[(i*2)+1];
				tab[(i*2)+1]=0.5;
			}
			else //2 syny
			{
				int z;
				int j=0;
				int t=i;
				i=(i+1)*2;
				int max=i;
				while(z!=1)
				{
					if(tab[(i*2)+1]!=0.5 && tab[(i+1)*2]!=0.5)
						j++;
					else if(tab[(i*2)+1]!=0.5 && tab[(i+1)*2]==0.5)
						j++;
					else if(tab[(i*2)+1]==0.5 && tab[(i+1)*2]!=0.5)
						j++;
					if(j==0)
						z=1;
					else
					{
						if(tab[(i+1)*2]>tab[(i*2)+1])
						{
							if(tab[max]<tab[(i+1)*2])
								max=(i+1)*2;
							i=(i+1)*2;
						}
						else
						{
							if(tab[max]<tab[(i*2)+1])
							max=(i*2)+1;
							i=(i*2)+1;
						}
						j--;
					}
				}
				//printf("%.0lf",tab[max]);
				tab[t]=tab[max];
				tab[max]=0.5;
			}
		ile--;
		printf("Usunieto %d",n);
	}
	else
		printf("Nie znaleziono %d\n",n);
}

int main()
{
	int i,jest;
	for(i=0;i<MAX;i++)
		tab[i]=0.5;
	int dane[12] = {18, 11, 6, 30 ,21 ,19, 8, 22, 23, 5, 0 , 6 };
	for(i=0;i<12;i++)
	{
		wstaw(dane[i]);
		ile++;
	}
	printf("\nCo znalezc?\n");
	scanf("%d",&i);
	jest=szukaj2(i);
	if(jest==0)
		printf("Nie znaleziono %d\n",i);
	else
	{
		if(jest==MAX+1)
			jest=0;
		printf("Znaleziono %d na %d pozycji",i,jest);
	}
	drukuj();
	printf("\n\nCo usunac?\n");
	scanf("%d",&i);
	usun(i);
	drukuj();
}
