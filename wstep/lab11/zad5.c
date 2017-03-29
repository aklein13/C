#include <stdio.h>
#include <math.h>



int main()
{
	int tab[100][100];
	int p;
	for(p=0;p<100;p++) //zerowanie
	{
		tab[p][0]=1;
		tab[p][p]=1;
	}
	
	int n,k;
	printf("Podaj n i k\n");
	scanf("%d",&n);
	scanf("%d",&k);
	if(k>n)
	{
		printf("BLAD");
		return 0;
	}
	
	int j;
	for(p=1;p<100;p++)
	{
		for(j=0;j<p;j++)
		{
			if(j==0)
			tab[p][j]=tab[p-1][j];
			else
			tab[p][j]=tab[p-1][j-1]+tab[p-1][j];
		}
	}
	
	printf("%d nad %d to: %d",n,k,tab[n][k]);
	return 0;
}
