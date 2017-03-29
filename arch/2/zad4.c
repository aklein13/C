#include <stdio.h>
//petla =,,,= (liczy ile jest jedynek w zapisie binarnym)
//przyklad: -68233217 to 11111011 11101110 11010111 11111111 (w 32 bit)
// i jest w tym 16 3x1 obok siebie
int main () 
{
	int x, x2;
	printf("Podaj liczbe x: ");
	scanf("%d",&x);
	asm volatile 
	(
	".intel_syntax noprefix;"
	"mov eax,%1;"
	"xor ebx,ebx;" //ebx to licznik 3x1 obok siebie
	"xor ecx,ecx;"
	"xor edx,edx;"
	
	"petla:"
	"shl eax;"
	"jnc a0;" //jesli nie ma przenisienia to skacze do a0 i zeruje licznik 3
	"inc edx;"
	"cmp edx,3;"
	"jz a2;"
	"jmp a1;"
	
	"a0:"
	"xor edx,edx;"
	"jmp a1;"
	
	"a2:"
	"inc ebx;"
	"shr eax;"
	"shr eax;"
	"dec ecx;"
	"dec ecx;"
	"or eax,-1073741824;" // ta liczna w zapisie 32bit to 11000...0
	"jmp a0;"
	
	"a1:"
	"cmp ecx,31;" // odejmowanie bez odejmowania (sub to zwykle odejmowanie)
	"jz koniec;" //sprawdzanie czy wynik poprzedniej operacji to 0
	"inc ecx;"
	"jmp petla;" // bezwarunkowy skok do etykiety
	
	"koniec:"
	"mov %0,ebx;"
	
	".att_syntax prefix;"
	:"=r" (x2)
	:"r" (x)
	:"eax","ebx","ecx","edx"
	);
	printf("Sprawdzana liczba = %d\nIlosc 3 jedynek obok siebie w zapisie binarnym = %d\n",x,x2);
return 0;
}
