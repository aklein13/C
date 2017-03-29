#include <stdio.h>
#include <math.h>
#include <ctype.h>
#include <stdlib.h>

typedef struct 
	{
		double a,b,c;
	} trojkat;
	

double obwod(trojkat t1)
{
	return t1.a+t1.b+t1.c;
}

float pole(trojkat t1)
{
	double ob;
	ob=obwod(t1)/2;
	
	return sqrt(ob*(ob-t1.a)*(ob-t1.b)*(ob-t1.c));
}

int main()
{
	trojkat t1;
	printf("Podaj boki trojkata a, b i c\n");
	scanf("%lf", &(t1.a));
	scanf("%lf", &(t1.b));
	scanf("%lf", &(t1.c));
	printf("Obwod wynosi: %lf\n", obwod(t1));
	printf("Pole wynosi: %lf\n",pole(t1));
	return 0;
}
