#include <stdio.h>
zamien (int *x, int *y)
{
	int temp=*y;
	*y=*x;
	*x=temp;
}

main ()
{
	int x,y;
	printf("Podaj x ");
	scanf("%d",&x);
	printf("Podaj y ");
	scanf("%d",&y);
	zamien(&x,&y);
	printf("x to %d ",x);
	printf("y to %d ",y);
}
