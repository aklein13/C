 #include <stdio.h>
 void main() 
 {
 int licz,x,y,n;
printf("Podaj liczbe\n");
scanf("%d",&licz);
printf("liczba: %d\n",licz);
printf("jej ost cyfra to %d\n",licz%10);
x=licz%10;
y=(licz-x)/10;
printf("liczba bez ost cyfry to %d\n",y);
}
