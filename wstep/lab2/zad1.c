 #include <stdio.h>
 void main() 
 {
 float a; /* deklaracja zmiennej i czyli nazwa typu zmiennej oraz jej nazwa*/
float b;
float c;
float del;
printf("Podaj a, b, c \n");
scanf("%f%f%f",&a,&b,&c);
del=b*b-(4*a*c);
if (del >= 0)
{printf("Pierwiastki istnieja");}
else
printf("Pierwiastki nie istnieja \n");
}
