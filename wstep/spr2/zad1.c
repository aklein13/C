#include <stdio.h>

main()
{
	int i, a;
	char tab[9];
	char znak;
	a=0;
	printf("Podaj slowo\n");
	for(i=0;i<9;i++)
	{
		scanf("%c",&tab[i]);
		getchar();
	}
	for(i=0;i<9;i++)
	{
		if(tab[i]=='a')
		{a=i;}
	}
	if(a==0)
	{printf("Brak litery a");}
	else
	printf("Ostatnie miejsce litery a to %d",a);
}
