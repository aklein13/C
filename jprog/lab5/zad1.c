#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>


void dzielenie(int n, int k, int* q, int* r)
{
	while (n>=k)
	{
		n=n-k;
		(*q)++;
	}
	*r=n;
}

int main()
{
	int n, k, q, r;
	q=0;
	r=0;
	printf("Podaj n i k(!=0)\n");
	scanf("%d",&n);
	scanf("%d",&k);
	dzielenie(n,k, &q, &r);
	printf("%d / %d = %d * %d + %d", n, k, k, q, r);
	return 0;
}
