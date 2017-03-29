#include <stdio.h>

int main()
{
	int a, b;
	a=2; b=4;
	if ((a=2) & (b=4)) printf(" TAK\n");
	else printf(" NIE D:\n");
	// cos innego
	int c=((-1)<<8)>>16;
	printf("%d",c);
}
// NIE, bo koniunkcja przypisania wartosci if dla a i b a!=b, wiec ma 
//wartosc 0, czyli else
