#include <stdio.h>

main()
{
	int tab[3][3]={{1,2,3},{2,3,1},{3,1,2}};
	int tabb[3];
	int i,j,c;
	j=0;
	c=0;

	for (i=0;i<3;i++) //wiersze
	{
	tabb[i]=tab[i][j]*tab[i][j+1]*tab[i][j+2];
	if(tabb[i]!=tabb[i-c])
		{
		printf("Macierz nie jest okay\n");	return 0;}
	c++;
	}

	c=0;
	i=0;

	for (j=0;j<3;j++) //kolumny
	{
	tabb[j]=tab[i][j]*tab[i+1][j]*tab[i+2][j];
	if(tabb[j]!=tabb[j-c])
	{
	printf("Macierz nie jest okay\n");	return 0;}
	c++;
	}
	
	printf("Macierz jest okay\n");
}
