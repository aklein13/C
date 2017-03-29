#include <stdio.h>

main()
{
	
	int n,k,i,w,c; //c-ile cyfr	w-rzadek/obliczenia wysokosci
	w=0;
	k=0;
	i=1;
	c=0;
	printf("Podaj n\n");
	scanf("%d",&n);
	int tab[n];
	while(i<=n) //tablica od 1 do n
	{
		tab[i-1]=i;
		i++;
	}
	while(w<n)	//wysokosc
	{
		k++;
		w=k*(k+1)/2;
	}
	k--;
	w=1;
	while(w<=n)
	{
		for(i=0;i<k;i++)
		{
			putchar(' ');	
		}
		for(i=0;i<w;i++)
		{
			if(c<n){
			printf("%3d",tab[c]);
			c++;}
			else if(c>=n)
			{return 0;}
		}
	putchar('\n');
	k--;
	w++;
	}
}
