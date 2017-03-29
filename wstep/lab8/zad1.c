#include <stdio.h>

char progowa(int a, int b)
{
	int wyn;
	char znak;
	wyn=a*b;
	if(a*b>100)
	{znak='a';}
	else if(a*b<100)
	{znak='b';}
	else if(a*b==100)
	{znak='c';}
	return znak;
}

main()
{
	int a,b;
	printf("Podaj a i b\n");
	scanf("%d",&a);
	scanf("%d",&b);
	printf("%c",progowa(a,b));
}
