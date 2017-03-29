#include<stdio.h>
#include<stdlib.h>

// Oblicza najwiekszy wspolny dzielnik przy zalozeniu, ze
//   n >= 0  i  k >= 0  oraz
//   n+k > 0  czyli argumenty nie sa jednoczesnie rowne zeru

int nwd(int n, int k)
{
	int i,max,zn;
  if(n<k)
  max=k;
  else
  max=n;
  for(i=1;i<max;i++)
  {
	  if(n%i==0 && k%i==0)
	  {
		  zn=i;
	  }
  }
  return zn;
}

main () {
  int n,k,wyn,max;
  printf("Podaj dwie liczby naturalne: ");
  scanf("%i", &n); scanf("%i", &k);
  wyn=0;
  wyn=nwd(n,k);
  if (wyn!=0)
  printf("\nnwd to %d",wyn);
  else
  printf("\nnwd to 1");
}
