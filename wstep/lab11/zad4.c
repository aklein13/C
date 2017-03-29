#include <stdio.h>
#include <math.h>

double hoe(int n, int k, double p)
{
	return exp(-2*(pow((n*p-k),2)/n));
}

int main()
{
	int n, k;
	double p,prawd,wyn;
	printf("Podaj n, k oraz p\n");
	scanf("%d",&n);
	scanf("%d",&k);
	scanf("%lf",&p);
	if(k>n)
	{
		printf("BLAD");
		return 0;
	}
	else if(p>1 || p<0)
	{
		printf("BLAD");
		return 0;
	}
	prawd=hoe(n,k,p);
	wyn=prawd*pow(p,k)*pow((1-p),(n-k));
	printf("Prawdopodobienstwo to %lf\n",wyn);
	return 0;
}
