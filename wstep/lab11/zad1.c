#include <stdio.h>

int newt(int n, int k)
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
	printf("Podaj n i k\n");
	scanf("%d",&n);
	scanf("%d",&k);
	 if(k>n)
		printf("BLAD");
		return 0;
	printf("%d nad %d to: %d",n,k,newt(n,k));
	return 0;
}
