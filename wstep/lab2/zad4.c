 #include <stdio.h>
 void main() 
 {
 int a, b, c;
printf("Podaj liczbe calkowita\n");
scanf("%d",&a);
printf("liczba: %d\n",a);
while (a>0)
{
	b=a%8;
	printf("%d\n",b);
	a=a/8;
}

}
