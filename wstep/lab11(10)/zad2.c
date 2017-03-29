#include <stdio.h>

int fibo(int n)
{
	if (n==1 || n==2)
	return 1;
	
	else if(n==0)
	return 0;
	
	else
	return fibo(n-1)+fibo(n-2);
}

main()
{
	int n,wyn;
	printf("Podaj n\n");
	scanf("%d",&n);
	printf("%d wyraz ciagu fibo to: ",n);
	wyn=fibo(n);
	printf("%d\n",wyn);
	for(n=1;n<10;n++)
	{
		fibo(n);
		wyn=fibo(n);
		printf("%d ",wyn);
	}
}
