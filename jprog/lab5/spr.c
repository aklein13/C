#include <stdio.h>
#include <math.h>

typedef struct
{
	char nazwa[20];
	float a,b,c,d;
	float h;
}	czworokat;

float obwod(czworokat c1)
{
	return c1.a+c1.b+c1.c+c1.d;
}

double pole(int a, int h)
{
	double ah;
	ah=a*h;
	return ah/2;
}

int main()
{
	czworokat c1;
	printf("Podaj nazwe czworokata\n");
	scanf("%s",c1.nazwa);
	printf("Podaj dlugosci 4 bokow czworokata %s\n",c1.nazwa);
	scanf("%f",&c1.a);
	scanf("%f",&c1.b);
	scanf("%f",&c1.c);
	scanf("%f",&c1.d);
	printf("Podaj wysokosc czworokata %s\n",c1.nazwa);
	scanf("%f",&c1.h);
	int ob;
	ob=obwod(c1);
	printf("Obwod czworokata %s w int: %8d\n",c1.nazwa,ob);
	float pol;
	pol=pole(c1.a,c1.h);
	printf("Pole czworokata %s w float: %6.2f\n",c1.nazwa,pol);
	return 0;
}
