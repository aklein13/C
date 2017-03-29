#include <stdio.h>
int mine(int min)
{
	
	int tab[10]={5,2,6,9,3,9,4,13,7,1};
	min=*tab;
	int i;
	for(i=1;i<10;i++)
	{
		if(*(tab+i)<min)
		{
			min=*(tab+i);
		}

	}
	return min;
}

main()
{
	
	int min;
	min=mine(min);
	printf("Najmniejszy to: %d\n",min);
}
