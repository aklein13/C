#include <stdio.h>

main()
{
	int i;
	float tab[4][4]={{0,0,0,1},{0,0,0,2},{0,0,0,3},{1,2,3,4}};

	for(i=0;i<4;i++)
	{
		if(tab[i][4]!=tab[4][i])
		{
			printf("Zle");
			return 0;
		}
	}
	
	printf("OK");
}
