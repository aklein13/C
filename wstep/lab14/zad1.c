#include <stdio.h>
#include <string.h>

int main()
{
	struct osoba
	{
		char imie[30];
		char nazwisko[40];
		int wiek;
	};
	struct osoba o1,o2;
	
	strcpy(o1.imie,"Ewa");
	strcpy(o1.nazwisko,"Rajska");
	o1.wiek=20;
	
	strcpy(o2.imie,"Adam");
	strcpy(o2.nazwisko,"Rajski");
	o2.wiek=22;
	
	printf("1. %s %s %d\n",o1.imie, o1.nazwisko, o1.wiek);
	printf("2. %s %s %d\n",o2.imie, o2.nazwisko, o2.wiek);
	return 0;
}
