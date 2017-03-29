#include <stdio.h>

main()
{
	int n,i,d;
	char c;
	printf("Podaj dlugosc slowa\n");
	scanf("%d",&n);
	d=n;
	d--;
	char tab[n];
	printf("Podaj slowo\n");
	for(i=0;i<n;i++)
	{
		scanf("%c",&tab[i]);
		c=getchar();
		tab[i]=c;
	}
	printf("To slowo od konca to: ");
	for(i=0;i<n;i++)
	{
		printf("%c ",tab[d]);
		d--;
	}
	putchar('\n');
}

