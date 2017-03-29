#include <stdio.h>

main()
{
int a,h,i,j,k,s;
k=0;
i=0;
j=1;

char znak;
znak='*';
printf("Podaj wysokosc oraz dlugosc rownolegloboka\n");
scanf("%d",&h);
s=h;
scanf("%d",&a);
while(i<h)
{
	while(j<s)
	{
	printf(" ");
	j++;
	}
	while(k<a)
	{
	printf("%c",znak);
	k++;
	}
printf("\n");
s--;
k=0;
j=1;
i++;
}
printf("\n");
}
