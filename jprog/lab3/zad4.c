#include <stdio.h>
#include <limits.h>
#include <float.h>
 
int main()
{
	double x;
	x=1.0;
	while(1.0+x>1.0)
	x=x/2.0;
	printf("ziarno double: %le\n",x);
	
	float y;
	y=1.0;
	while(1.0+y>1.0)
	y=y/2.0;
	printf("ziarno float: %e\n",y);
	
	long double z;
	z=1.0;
	while(1.0+z>1.0)
	z=z/2.0;
	printf("ziarno long double: %Lle\n",z);
	
}
