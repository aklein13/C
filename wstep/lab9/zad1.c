#include <stdio.h>

double fun(double x)
{
	return x*x;
}

double fun2(int k, double x)
{
	double wyn;
	if (k==0)
	{
		printf("%lf",x);
		return x;
	}
	else
	x=fun(x);
	k--;
	return fun2(k,x);
}

main()
{
	int k,i;
	double x;
	printf("Podaj liczbe\n");
	scanf("%d",&k);
	printf("Podaj x\n");
	scanf("%lf",&x);
	printf("Dla %d wywoalania wynik to: ",k);
	fun2(k,x);
}
