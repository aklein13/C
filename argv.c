#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>

int main( int argc, char *argv[] )
{
	int ile=argc;
	printf("Liczy ze: %d a sa to:\n",ile);
	int i;
	for(i=0;i<ile;i++)
	{
		printf("%s ",argv[i]);
	}
	printf("\n");
	return 0;
}
