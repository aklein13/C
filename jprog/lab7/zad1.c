#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>

int main( int argc, char *argv[] )
{
	int ile=argc-1;
	int i;
	for(i=0;i<ile;ile--)
	{
		printf("%s ",argv[ile]);
	}
	printf("\n");
	return 0;
}
