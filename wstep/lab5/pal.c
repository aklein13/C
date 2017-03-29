#include <stdio.h>
#include <string.h>
 
int main()
{
   char tekst[100];
   int start, srodek, kon, dl = 0;
   printf("Podaj jakis tekst\n");
   gets(tekst);
   while (tekst[dl] != '\0')
   {
      dl++;
  }
 
   kon=dl-1;
   srodek=dl/2;
 
   for (start=0;start<srodek;start++)
   {
      if (tekst[start]!=tekst[kon])
      {
         printf("Nie jest palindromem.\n");
         return 0;
      }
      kon--;
   }
   if (start==srodek)
   {
      printf("Jest palindromem.\n");
	}
}
