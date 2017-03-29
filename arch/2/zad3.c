#include <stdio.h>
//petla =,,,= (liczy ile jest jedynek w zapisie binarnym)
int main () 
{
	int x, x2;
	printf("Podaj liczbe x: ");
	scanf("%d",&x);
	asm volatile 
	(
	".intel_syntax noprefix;"
	"mov eax,%1;"
	"xor ebx,ebx;"
	"xor ecx,ecx;"
	
	"petla:"
	"shl eax;"
	
	"jnc a1;"
	"inc ebx;"
	
	"a1:"
	"cmp ecx,31;" // odejmowanie bez odejmowania (sub to zwykle odejmowanie)
	"jz koniec;"
	"inc ecx;"
	"jmp petla;" // bezwarunkowy skok do etykiety
	
	"koniec:"
	"mov %0,ebx;"
	
	".att_syntax prefix;"
	:"=r" (x2)
	:"r" (x)
	:"eax","ebx","ecx"
	);
	printf("Sprawdzana liczba = %d\nilosc jedynek w zapisie binarnym = %d\n",x,x2);
return 0;
}
