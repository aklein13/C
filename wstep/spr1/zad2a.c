#include <stdio.h>

main()
{
	int i,n;
	double w;
	i=0;
	printf("Podaj liczbe n\n");
	scanf("%d",&n);
	printf("Parzyste dzielniki liczby %d to:",n);
	while(i<n)
	{
		i=i+2;
		w=n%i;
		if(w==0)
		{
		printf("%3d",i);
		}
	}
}
