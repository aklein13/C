#include <stdio.h>

main()
{
int i,j,k;
char tab[11]={'a','l','a',' ','m','a',' ','k','o','t','a'};
char znak;
i=0;
k=0;
printf("Podaj szukana litere\n");
scanf("%c",&znak);
while(i<11)
{
	if(tab[i]==znak)
	{
	printf("jest\n");
	k++;
	i++;
	}
	else
i++;
}
i=0;
if (k>0)
{
	printf("Wykryto %d znakow\n",k);
	printf("Cala tablica: ");
	for(i=0;i<11;i++)
	{
	printf("%c",tab[i]);
	}
	printf("\n");}
else
printf("Nie bylo D:\n");
}
