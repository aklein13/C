//Zadanie 2
#include <stdio.h>
#include <math.h>

double deltoid(double a, double b, double alpha)
{
	return a*b*sin(alpha*M_PI/180);
}

main()
{
	double a,b,alpha;
	printf("Podaj a, b i kat alpha\n");
	scanf("%lf",&a);
	scanf("%lf",&b);
	scanf("%lf",&alpha);
	printf("Pole deltoidu to: %lf",deltoid(a,b,alpha));
}
