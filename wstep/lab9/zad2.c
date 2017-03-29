#include <stdio.h>
#include <math.h>

double trzykat(double b, double k)
{
	double rad;
	double R;
	rad=k*M_PI/180;
	R=(b/sin(rad))/2;
	printf("%lf",R);
	return R;
}

main()
{
	
	double b,k;
	printf("Podaj bok\n");
	scanf("%lf",&b);
	printf("Podaj kat\n");
	scanf("%lf",&k);
	trzykat(b,k);
}
