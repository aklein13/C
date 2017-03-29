#include <stdio.h>


int main () {
	int x=-1; //dla -1 bedzie 2 bo w bitowym (1111...1) przenosi shl jedynke to JNC nie skacze
	int x2=0;
	asm volatile 
	(
	".intel_syntax noprefix;"
	"mov eax, %1;"
	"xor ebx, ebx;" //zerowanie rejestru
	"shl eax;"
	
	"jnc a1;" // flaga sprawdza wynik ostatniej operacji arytmetycznej
	"inc ebx;" //dodawanie o jeden. odejmowanie to dec
	
	"a1:"
	"shl eax;"
	
	"jnc a2;"
	"inc ebx;"
	
	"a2:"
	"mov %0,ebx;"

	".att_syntax prefix;"
	:"=r" (x2)
	:"r" (x)
	:"eax","ebx"
	);
	printf("x=%d x2=%d",x,x2);
return 1;
}
