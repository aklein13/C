//Zadanie 3
#include <stdio.h>
#include <math.h>

int silnia(int i)
{
	if (i==1)
	return 1;
	else if(i==0)	return 0;
	else
	return i*silnia(i-1);
}

double tylor(int n, int x)
{
	int i;
	double suma;
	suma=0;
	for(i=0;i<n;i++)
	{
		suma=suma+(pow(-1,i)*(pow(x,2*i)/silnia(2*i)));
	}
	return suma;
}
main()
{
	int x,n;
	printf("Podaj x i n\n");
	scanf("%d",&x);
	scanf("%d",&n);
	printf("Wynik to: %lf",tylor(n,x));
}
