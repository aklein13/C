#include <stdio.h>

main()
{
	int i,n,s;
	double w;
	i=1;
	printf("Podaj liczbe n\n");
	scanf("%d",&n);
	printf("Dzielniki liczby %d to:  1",n);
	while(i<n)
	{
		i++;
		w=n%i;
		if(w==0)
		{
		printf("%3d",i);
		s=s+i;	//suma tych dzielkow
		}
	}
	s=s-n-1;
	printf("\nSuma dzielkow tej liczby (bez 1 oraz %d) to: %d",n,s);
}
