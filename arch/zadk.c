#include <stdio.h>
#include <stdlib.h>

int main()
{

   char *s="aj";

   int x,y;
asm volatile
(
".intel_syntax noprefix;"
"xor ebx, ebx;"
"xor edx, edx;"
"CLD;"
  "mov edi, %2;"
  "mov ebx, %2;"

"petla:"
"mov eax, 0;"
"scasb;"
"jz kon;"
"sub edi, 1;"
"mov eax, 'a';"
"scasb;"
"je znalezione;"
"sub edi, 1;"
"mov eax, 'b';"
"scasb;"
"je znalezione;"
"jmp petla;"

"znalezione:"
"mov ecx, 2;"
//"add edi, 1;"
"mov eax, 'r';"
"repne scasb;"
"je petla;"
"mov edx, edi;"
"jmp dalej;"

"dalej:"
"mov eax, 'r';"
"scasb;"
"je kuniec;"
"jmp dalej;"

"kuniec:"
"sub edx, ebx;"
"sub edx, 2;"
"sub edi, ebx;"
"sub edi, edx;"
"mov eax, edi;"
"sub edx, 1;"
"inc eax;"
"mov %0,edx;"
"mov %1, eax;"
"jmp jeszcze;"
"kon:"
"mov %0,0;"
"mov %1,0;"
"jeszcze:"
".att_syntax prefix;"
  : "=r" (x), "=r" (y)
  : "r" (s)
  : "eax", "ebx", "ecx", "edx"

);
printf("%hd, %hd\n",x,y);
}
