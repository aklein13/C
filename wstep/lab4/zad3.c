#include <stdio.h>

main()
{
int i,j,k;
char tab[11]={'a','l','a',' ','m','a',' ','k','o','t','a'};
char tab2[11]={'_','_','_','_','_','_','_','_','_','_','_'};
char znak;

k=0;
j=0; //zgadniete litery
for(i=0;i<11;i++)
		{
		printf("%c",tab2[i]);
		}
i=0;
while (j<11){
printf("Zgadnij litere\n");
scanf("%c",&znak);
getchar();

	while(i<11)
	{
		if(tab[i]==znak)
		{
		//printf("jest\n");
		tab2[i]=tab[i];
		k++;
		i++;
		}
		else
	i++;
	}
	i=0;
	if (k>0)
	{
		printf("Jest: ");
		for(i=0;i<11;i++)
		{
		printf("%c",tab2[i]);
		}
		i=0;
		j=j+k;
	}
	else if (k==0)
	{
	printf("Nie bylo D:");
	}
	printf("\n");
	k=0;
}
printf("KONIEC\n");
}
