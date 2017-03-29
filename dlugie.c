#include <stdio.h>

int main()
{
	int ttab[30]; //temp
	int tab[30]; //1 cyfra
	int tabb[30]; //2 cyfra
	int tabbb[31]; //wynik
	int d,dd,p,i,temp,przen,max,c;
	for(i=0;i<30;i++)
		{tab[i]=0;}
	for(i=0;i<30;i++)
		{tabb[i]=0;}
	for(i=0;i<31;i++)
		{tabbb[i]=0;}
	i=0;
	d=0;
	p=0;
	printf("Podaj pierwsza liczbe, aby zakonczyc podaj litere\n");
	while (scanf("%1d",&c) == 1)
		{
			ttab[i]=c;
			d++;
			i++;
		}
	dd=d;
	for (i=0;i<d;i++)
	{
		tab[dd-1]=ttab[i];
		dd--;
	}
	putchar('\n');
	i=0;
	printf("Podaj druga liczbe, aby zakonczyc podaj litere\n");
	getchar();
	
	while (scanf("%1d",&c) == 1)
		{
			ttab[i]=c;
			p++;
			i++;
		}
	dd=p;
	for (i=0;i<p;i++)
	{
		tabb[dd-1]=ttab[i];
		dd--;
	}
	putchar('\n');
	
	if (d>p)
	{max=d;}
	else if (p>=d)
	{max=p;}
	i=0;
	przen=0;
	temp=tab[d-1]+tabb[p-1];
	if(temp>9) //czy liczba ma wiecej cyfr
	{
		max++;
	}
	while (i<max) //dodawanie jak pisemne
	{
		temp=tab[i]+tabb[i]+przen;
		if(temp>9)
		{
			przen=1;
			temp=temp-10;
		}
		else if(temp<=9){przen=0;}
		tabbb[i]=temp;
		i++;
	}
	printf("Wynik to:\n");
	c=max;
	for(i=0;i<max;i++)
	{printf("%d",tabbb[c-1]);
	c--;}
	putchar('\n');
	return 0;
}
