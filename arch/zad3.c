#include <stdio.h>
//sprawdzenie zad3.s
int funkcja(int n)
{
	if (n==0 | n==1)
		return 1;
	else if(n==2)
		return 0;
	else
		return funkcja(n-1)+2*funkcja(n-2)-funkcja(n-3);
}

int main()
{
	int a=3;
	int wynik;
	wynik=funkcja(a);
	printf("wynik = %d\n",wynik);
	return 0;
}
