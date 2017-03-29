#include <stdio.h>

main()
{
	int a,b;
	printf("Podaj liczbe jakas\n");
	scanf("%d",&a);
	b=a%10;
	printf("Ostatnia liczba to: %d\n",b);
	a=(a-b)/10;
	printf("Liczba bez ostatniej cyfry to: %d\n",a);
}
