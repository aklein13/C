#include <stdio.h>

void sort(int i, int j,int tab[10], int n)
{
	int liczba;
	for (i=1;i<n;i++)
	{
		liczba=tab[i];
		for(j=i-1;j>=0 && tab[j]>liczba;j--)
		{
			tab[j+1]=tab[j];
			tab[j]=liczba;
		}
	}
}

void maax(int i, int j,int tab[10], int n)
{
	int max;
	int pos;
	for (i=n;i>1;i--)
	{
		max=tab[0];
		for(j=1;j<i;j++)
		{
			if(max<tab[j])
			{
				pos=j; max=tab[j];
			}
		}
	tab[pos]=tab[i];
	tab[i]=max;
	}
}

int main()
{
	int tab[10]={5,2,6,1,3,9,4,13,7,2};
	int n=10;
	int i, j;
	maax(i,j,tab,n);
	printf("Posortowane:\n");
	for(i=0;i<n;i++)
	{
		printf("%d ",tab[i]);
	}
	return 0;
}
