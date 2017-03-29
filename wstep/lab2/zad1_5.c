 #include <stdio.h>
 void main() 
 {
 float a; 
printf("Podaj liczbe naturalna do 3 cyfr \n");
scanf("%f",&a);
while ((a>1000)&&(a<0)){printf ("Podales zla liczbe \n");}

if (a<10)
{printf("Jest to liczba 1 cyfrowa\n");}
else if ((a>= 10)&&(a<100))
{printf("Jest to liczba 2 cyfrowa\n");}
else if ((a>=100)&&(a<1000))
{printf("Jest to liczba 3 cyfrowa \n");}
else 
printf("Zla liczba \n");
}
