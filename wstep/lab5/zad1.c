#include <stdio.h>

main()
{
	int n,i;
	printf("Podaj liczbe n\n");
	scanf("%d",&n);
	double tab[n];
	double tab2[n];
	double w,s;
	printf("Podaj elemnty tablicy pierwszej\n");
	for(i=0;i<n;i++)
	{
		scanf("%lf",&tab[i]);
		getchar;
	}
	printf("Podaj elemnty tablicy drugiej\n");
	for(i=0;i<n;i++)
	{
		scanf("%lf",&tab2[i]);
		getchar;
	}
	for(i=0;i<n;i++)
	{
		w=tab[i]*tab2[i];
		s=s+w;
	}
	printf("Iloczyn sklarny to: %lf\n",s);	
}

