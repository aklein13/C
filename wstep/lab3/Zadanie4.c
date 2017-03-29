#include <stdio.h>
 
main()
{
    int i,n,k,s;
s=1;
i=0;
    printf("Podaj wykladnik\n");
	scanf("%d",&k);
    printf("Podaj liczbe potegowana\n");
	scanf("%d",&n);
while (i<k)
{
	s=s*n;
	i++;
}
printf("%d do potegi %d wynosi: %d\n",n,k,s);
}
