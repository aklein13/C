#include <stdio.h>

main()
{
	int tab[4][4]={{1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16}};
	int i,j,c;
	for (i=0;i<4;i++) //wiersze
	{
		c=i+1;
		printf("wiersz %d: ",c);
		for(j=0;j<4;j++)
		{
			printf("%1d ",tab[i][j]);
		}
		putchar('\n');
	}
putchar('\n');
	for (i=0;i<4;i++) //kolumny
	{
		c=i+1;
		printf("kolumna %d: ",c);
		for(j=0;j<4;j++)
		{
			printf("%1d ",tab[j][i]);
		}
		putchar('\n');
	}
}
