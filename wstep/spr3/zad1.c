//Arkadiusz Klein  grupa B
//Zadanie 1
#include <stdio.h>

int fun(int n)
{
	if(n==1)	return 2;
	else if(n==2)	return 3;
	else if (n==3)	return 4;
	else if (n==0)	return 0;
	else
	{
		return 7*fun(n-1)+3*fun(n-2)-5*fun(n-3);
	}
}

main()
{
	int n,i;
	printf("Podaj n\n");
	scanf("%d",&n);
	if(n<4)
	{
		printf("Blad");
	}
	else
	printf("%d wyraz ciagu to: %d\n",n,fun(n));
	printf("10 pierwszych wyrazow ciagu to: ");
	for(i=0;i<10;i++)
	{
		printf("%d ",fun(i));
	}
}
