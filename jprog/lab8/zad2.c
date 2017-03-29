#include <stdio.h>
#define CZYT(zmienna,typ) \
{ printf("Podaj wartosc a: "); scanf("%"#typ,&zmienna); printf("%"#typ,zmienna ); }

int main()
{
	int a;
	double b;
	CZYT(a,i)
	CZYT(b,lf)
	return 0;
}
