#include <stdio.h>

main ()
{
     int a, n, w; // w - wynik  n - ilosc cyfr  a - cyfra
     a=0;
     printf("Podaj ilosc cyfr w zapisie 8-kowym \n");
     scanf("%d",&n);
     printf("Podaj te cyfry cyfr \n");
     while (n>0)
     {
        scanf("%d",&a);
        w=w*8+a;
        n--;
	}
     printf("Wyniki w postaci dziesietnej to: %d\n",w);
}
