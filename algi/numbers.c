#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main()
{
	int i,n,rodzaj;
	printf("Podaj ilosc liczb do pliku input.txt\n");
	scanf("%d",&n);
	printf("Jakie to maja byc liczby?\n1. Losowe\n2. Rosnace\n3. Malejace\n");
	scanf("%d",&rodzaj);
	FILE *input = fopen("input.txt", "w");
	int x;
	if (rodzaj==1)
	{
		srand(time(NULL));
		for(i=0;i<n;i++)
		{
			x = rand()%1000;
			fprintf(input,"%d\n",x);
		}
	}
	else if(rodzaj==2)
	{
		for(i=0;i<n;i++)
			{
				fprintf(input,"%d\n",i);
			}	
	}
	else if(rodzaj==3)
	{
		for(i=n;i>0;i--)
			{
				fprintf(input,"%d\n",i-1);
			}	
	}
	else
		printf("Cos zjebales\n");
	fclose(input);
	printf("Wygenerowano %d liczb\n",n);
	return 0;
}
