#include <stdio.h>
#include <limits.h>
#include <float.h>
 
int main()
{
    short int si=SHRT_MIN;
    int i=INT_MIN;
    long int li=LONG_MIN;
	long long int lli;
	float f=FLT_MIN;
	double d=DBL_MAX;
	long double ld=LDBL_MAX;
	
	printf("(short int min)-1: %i\n",i-1);
	printf("(int min)-1: %i\n",i-1);
	printf("(long int min)-1: %li\n",li-1);
	printf("(long long int min)-1: %lli\n",lli-1);
	printf("(float min)/2: %e\n",f/2);
	printf("(double max)*2: %le\n",d*2);
	printf("(long double max)*2: %Le\n",ld*2);
}
