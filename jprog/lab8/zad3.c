#include <stdio.h>
#define PETLA(kom1,warunek,kom2) \
{ kom1; while(warunek){kom2; kom1;} }

int main()
{
	int a=0;
	int b=0;
	int i=0;
	PETLA(a++, i<5, b++; i++);
	printf("\na: %d\nb: %d\n",a,b);
	return 0;
}
