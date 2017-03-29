#include <stdio.h>

double del(double a, double b, double c)
{
	double delta;
	int wyn;
	delta=(b*b)-4*a*c;
	if(delta>0)
	{
		wyn=2;
	}
	else if(delta==0)
	{
		wyn=1;
	}
	else if(del<0)
	{
		wyn=0;
	}
	return wyn;
}

main()
{
	double a;
	double b;
	double c;
	int ile;
	printf("Podaj a, b, c\n");
	scanf("%lf",&a);
	scanf("%lf",&b);
	scanf("%lf",&c);
	ile=del(a,b,c);
	if(ile==1)
	{
		printf("Ma 1 pierwiastek");
	}
	else if (ile==2)
	{
		printf("Ma 2 pierwiastki");
	}
		else if(ile==0)
	{
		printf("Nie ma pierwiastkow");
	}
}
