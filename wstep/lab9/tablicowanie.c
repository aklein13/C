#include<stdio.h>
#include<math.h>

#define dol_x -0.9
#define gora_x 8
#define krok_x 0.1


double funkcja(x)
{
	//a return ((x*x*x)/27)-((2*x*x)/9)+(x/3)+2; 	
	return log(x+1); //b
}


int main () {
  double x;
  printf("\nTABLICOWANIE FUNKCJI:\n");
  printf("\n Argument |   Wartosc   ");
  printf("\n----------+-------------");
  for (x=dol_x; x<=gora_x; x=x+krok_x)
    printf("\n %8.4lf | %10.4lf ", x, funkcja(x));
  printf("\n\n");

  return 0;
}

