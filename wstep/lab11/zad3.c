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
	int n, k, i;
	double p,prawd,wyn;
	printf("Podaj n, k oraz p\n");
	scanf("%d",&n);
	scanf("%d",&k);
	scanf("%lf",&p);
	wyn=0;
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
	for(i=0;i<=k;i++)
	{
		prawd=newt(n,i);
		wyn=wyn+(prawd*pow(p,i)*pow((1-p),(n-i)));
	}
	printf("Prawdopodobienstwo to %lf\n",wyn);
	return 0;
}
