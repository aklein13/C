#include<stdio.h>
#include<stdlib.h>
int  k, cz[1000];

void czyn(int n, int dziel)
{
	int i;
	for (i=0;i<n;i++)
  {
	  if(n%dziel==0)
	  {
		  cz[k]=dziel;
		  k++;
		  dziel++;
	  }
	  else
		if(dziel<n)
		{
			dziel++;
		}
	}
}

int main () {
	
  int  n,i;
  printf("Podaj liczbe naturalna wieksza niz 1: "); scanf("%i", &n);
  while (n <= 1) {
    printf("Podaj liczbe naturalna wieksza niz 1: "); scanf("%i", &n);
  }
  k=0;
  czyn(n, 2);
  printf("\n  Czynniki pierwsze liczby %i:\n  ", n);
  for (i=0; i<k; i=i+1)  printf("  %i", cz[i]);
  printf("\n\n");
  return 0;
}
