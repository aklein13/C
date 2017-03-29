//Zadanie 4
#include <stdio.h>

main()
{
	int tab[5]= {0,1,2,3,4}; 
	int min;
	int i;
	min=*tab;
	for (i=0;i<5;i++)
	{
	if(*(tab+i) <= min)
		{
			min=*(tab+i);
		}
	}
	printf("minimalny element to %d",min);
}
