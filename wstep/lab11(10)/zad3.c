#include <stdio.h>
#include <math.h>

int fibo(int n)
{
	if (n==1 || n==2)
	return 1;
	
	else if(n==0)
	return 0;
	
	else
	return fibo(n-1)+fibo(n-2);
}

double nierek(int n)
{
	return ((1/sqrt(5))*pow(1+sqrt(5))/2,n))-((1/sqrt(5))*pow((1-sqrt(5))/2,n));
}

main()
{
	int n,wyn;
	double nier;
	printf("Podaj n\n");
	scanf("%d",&n);
	printf("%d wyraz ciagu fibo to: ",n);
	wyn=fibo(n);
	printf("%d\n",wyn);
	nier=nierek(n);
}
