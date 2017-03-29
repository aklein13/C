#include <stdio.h>
//[rzadek] [kolumna]
main()
{
	int i,j,l,n;
	printf("Podaj rozmiar macierzy\n");
	scanf("%d",&n);
	int tab[n][n];
	int tabb[n][n];
	int wyn[n][n];
	
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			wyn[i][j]=0;
		}
	}
	printf("Podaj cyfry pierszej macierzy\n");
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			scanf("%d",&tab[i][j]);
		}
		printf("\n");
	}
	printf("Podaj cyfry drugiej macierzy\n");
	for(j=0;j<n;j++)
	{
		for(l=0;l<n;l++)
		{
			scanf("%d",&tabb[j][l]);
		}
		printf("\n");
	}
	
	for(i=0;i<n;i++)
	{
		for(l=0;l<n;l++)
		{
			wyn[i][l]=0;
			for(j=0;j<n;j++)
			{
				wyn[i][l]=wyn[i][l]+tab[i][j]*tabb[j][l];
			}
		}
	}
	
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			printf("%d ",wyn[i][j]);
		}
		putchar('\n');
	}
}
