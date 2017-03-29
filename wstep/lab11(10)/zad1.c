#include <stdio.h>

int silnia(int n)
{
	if (n==1)
	return 1;
	else
	return n*silnia(n-1);
}

main()
{
	int n,wyn;
	printf("Podaj n");
	scanf("%d",&n);
	wyn=silnia(n);
	printf("%d",wyn);
}
