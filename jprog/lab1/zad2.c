#include <stdio.h>

int main()
{
	char z;
	while(scanf("%c", &z)!=EOF)
	{
		printf("%c",z);
		putchar('\n');
	}
	return 0;
}
