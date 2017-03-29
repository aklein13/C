#include <stdio.h>

main()
{
int k,p,i,t; //k-ilosc  i-petla  p-wynik  t-podziel
printf("Podaj ilosc liczb\n");
scanf("%d",&k);
printf("Podaj przez co maja byc podzielne\n");
scanf("%d",&t);
i=0;
p=0;
if(t==0)
{printf("Nic nie jest podzielne przez 0\n");
return 0;}
else
printf("Oto %d pierwszych liczb podzielnych przez %d\n",k,t);
while (i<k)
{
	p=p+t;
	printf("%d ",p);
	i++;
}
printf("\n");
}
