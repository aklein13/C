#include <stdio.h>

main()
{
	int n,i,h,k,j;
	j=1;
	k=0;
	printf("Podaj wysokosc trojkata\n");
	scanf("%d",&n);
	h=n-1;
	while(k<n)
	{
	for(i=0;i<h;i++)
	{
		putchar(' ');
	}
	h--;
	for(i=0;i<j;i++)
	{
		putchar('*');
	}
	j=j+2;
	putchar('\n');
	k++;}
}
