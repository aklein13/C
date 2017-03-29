#include <stdio.h>
//5+5=10
int main()
{
	int x=5;
	int x2=999; 
	//assembler =,,,=  robi x2=x+x;
	asm volatile 
	(
	".intel_syntax noprefix;"	//skladnia intel. To nizej do att robi dodawanie
	"mov eax,%1;"	//przenosi %1 do eax i czysci eax
	"add eax,eax;"	//dodaje eax do eax. wynik idzie do tego 1
	"mov %0,eax;"	//przenosi eax do %0 czyli wynik do zmiennej z output
	".att_syntax prefix;"	//skladnia att
	:"=r" (x2)	//output. r to zmienna ma byc w rejestrze //to jest %0
	:"r" (x)	//input //to %1
	:"eax"	// eax to nazwa rejestru. Lista rejestrow niszczonych
	);
	//koniec assemblera
	printf("x=%d x2=%d\n",x,x2);
	return 0;
}
