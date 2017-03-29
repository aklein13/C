#include <stdio.h>
 
main()
{
    int i,n,s,w,j,t; //opis zmiennych x.x
s=1;
i=0;
j=1;
w=0;
    printf("Podaj liczbe n\n");
	scanf("%d",&n);
t=n-1;
while (j<n)
{

while (i<n)
{
	n=n-t;
	s=s*n;
	i++;
	t--;
}
w=w+s;
j++;}
printf("%d\n",w);
}
