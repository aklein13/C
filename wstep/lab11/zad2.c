#include <stdio.h>
#include <math.h>

double newt(int n, int k)
{
	if(n==0)
		return 1;
	else if(n==k)
		return 1;
	else if(k==0)
		return 1;
	else 
		return newt(n-1,k)+newt(n-1,k-1);
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
	prawd=newt(n,k);
	wyn=prawd*pow(p,k)*pow((1-p),(n-k));
	printf("Prawdopodobienstwo to %lf\n",wyn);
	return 0;
}
