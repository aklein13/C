#include <stdio.h>

main()
{
	int i,n;
	int tab[100];
	n=0;
	printf("Liczby podzielne przez 4:\n");
	for(i=0;i<400;i=i+4)
	{
		printf("%d",i);
		putchar(' ');
		tab[n]=i;
		n++;
	}
	printf("\nLiczby podzielne przez 4 od tylu:\n");
	for(i=0;n>i;n--)
	{
		printf("%d",tab[n-1]);
		putchar(' ');
	}
}
