#include <stdio.h>


int main () {
	int x=1;
	int x2=0;
	asm volatile 
	(
	".intel_syntax noprefix;"
	"mov eax, %1;"
	"shl eax;" // shl - shift left czyli przesuniecie w lewo
	"cmp eax,02;" 
	"je zapalony;" // if flaga to skocz do zapalony (jc to jest rowne (cmp))
	"mov eax, 17;"
	"jmp koniec;" //pomija zapalony
	"zapalony:"
		"mov eax,12;" //jesli warunek sprelniony to daje 12 zamiast eax
	"koniec:"
		"mov %0,eax;"
	".att_syntax prefix;"
	:"=r" (x2)
	:"r" (x)
	:"eax"
	);
	printf("x=%d x2=%d",x,x2);
return 1;
}
