#include <stdio.h>

main()
{
int k,p,i;
printf("Podaj ilosc liczb\n");
scanf("%d",&k);
i=0;
p=0;
printf("Oto %d kolejnych liczb parzystych\n",k);
while (i<k)
{
	p=p+2;
	printf("%d",p);
	i++;
}
printf("\n");
}
