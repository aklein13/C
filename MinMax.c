#include <stdio.h>

int main()
{
	int tab[10]={5,2,6,1,3,9,4,13,7,2};
	int min, max, i;
	max=tab[0];
	min=tab[0];
	for(i=1;i<10;i++)
	{
		if(tab[i]>max)
		{
			max=tab[i];
		}
		else if(tab[i]<min)
		{
			min=tab[i];
		}
	}
	printf("Najwiekszy element to: %d a najmniejszy to: %d\n",max,min);
	return 0;
}
