#include <stdio.h>
// ym robi [pq][^r]+r *,...,*
// ma byc 7,8 (printf("7,8"); -,,,-
int main () 
{
	char *s = "";
	int x,y;
	asm volatile 
	(
	".intel_syntax noprefix;"
	"mov ecx,%2;" //podany char
	"xor eax,eax;" //eax to pozycja
	"xor ebx,ebx;" //ebx to dlugosc
	
	"petla:"
	"mov dl, byte ptr[ecx+ebx];"
	"cmp dl, 0;"	//sprawdz, czy koniec
	"jz ZERO;"
	"cmp dl,'p';"
	"jz jest;"
	"cmp dl,'q';"
	"jz jest;"
	"inc ebx;"
	"jmp petla;"
	
	"jest:"
	"mov eax, ebx;"
	"inc ebx;"
	"mov dl, byte ptr[ecx+ebx];"
	"cmp dl, 0;"
	"jz ZERO;"
	"cmp dl,'r';"
	"jz clean;"
	"inc ebx;" //last change
	
	"petelka:"
	"mov dl, byte ptr[ecx+ebx];"
	"cmp dl, 0;"
	"jz ZERO;"
	"cmp dl,'r';"
	"jz koniec;"
	"inc ebx;"
	"jmp petelka;"
	
	"clean:"
	"inc ebx;"
	"xor eax, eax;"
	"jmp petla;"
	
	"koniec:"
	//"cmp eax,0;"
	//"jz ZERO;"
	"inc ebx;"
	"sub ebx,eax;"
	"jmp wyjscie;"
	
	"ZERO:"
	"xor ebx,ebx;"
	"xor eax,eax;"
	
	"wyjscie:"
	"mov %0,eax;"
	"mov %1,ebx;"
	".att_syntax prefix;"
	:"=r" (x), "=r" (y)
	:"r" (s)
	:"eax","ebx","ecx"
	);
	printf("%hd,%hd\n",x,y);
}
