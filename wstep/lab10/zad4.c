#include <stdio.h>
#include <stdlib.h>

void main()
{
	int n,min,i;
	printf("podaj ILEEEEE ");
	scanf("%d",&n);
	int *tab;
	tab = malloc( n * sizeof(int));
	for (i=0;i<n;i++)
	{
		scanf("%d",&*(tab+i));
	}
	
	min=*tab;
	
	for(i=1;i<n;i++)
	{
		if(*(tab+i)<min)
		{
			min=*(tab+i);
		}

	}
	printf("Najmniejszy to: %d\n",min);
}
