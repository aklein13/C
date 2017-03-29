#include <stdio.h>

main()
{
	int i,n,p,j,s,t;	//i,j-zmienna petel n-dana s-wynik p-wynik potegi liczby "t"		t-dziwna zmeinna (takie n2)
	p=1;
	s=0;
	printf("Podaj liczbe n\n");
	scanf("%d",&n);
	t=n;
	for(j=0; j<n; j++)  //petla dodajaca potegi liczb
	{	
		for(i=0; i<t; i++)  //petla potegujaca
		{
			p=p*t;
		}
		s=s+p;
		t--;
		p=1;
	}
	printf("Suma poteg: %d\n",s);
}
