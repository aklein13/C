#include <stdio.h>

main()
{
	int i;
	printf("Liczb parzyste:\n");
	for(i=0;i<200;i=i+2)
	{
		printf("%d",i);
		putchar(' ');
	}
}
