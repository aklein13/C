#include <stdio.h>

main()
{
	int i,f;
	double tab[10]={1,1,1,1,1,1,1,1,1,1};
	double tabb[10]={2,1,1,1,1,1,1,1,1,3};
	double wyn[10];
	f=9;
	for(i=0;i<10;i++)
	{
		wyn[i]=tab[i]-tabb[f];
		f--;
	}
	
	for(i=0;i<10;i++)
	{
		
	printf("%lf\n",wyn[i]);}
}
