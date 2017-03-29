#include <stdio.h>
#include <limits.h>
#include <float.h>
 
int main()
{
    short int simin;
    int imin;
    long int lmin;
	long long int llmin;
	float fmin;
	double dmin;
	long double ldmin;
	printf("rozmiar short int: %d\n",sizeof(simin));
	printf("rozmiar int: %d\n",sizeof(imin));
	printf("rozmiar long int: %d\n",sizeof(lmin));
	printf("rozmiar long long int: %d\n",sizeof(llmin));
	printf("rozmiar float: %d\n",sizeof(fmin));
	printf("rozmiar double: %d\n",sizeof(dmin));
	printf("rozmiar long double: %d\n\n",sizeof(ldmin));

        printf ("short int min: %i 		max: %i\n", SHRT_MIN ,  SHRT_MAX );
        printf ("int min: %i 		max: %i\n", INT_MIN ,  INT_MAX );
        printf ("long int min: %li		 max: %li\n", LONG_MIN ,  LONG_MIN );
        printf ("long long int min: %lli		 max: %lli\n", LLONG_MIN ,  LLONG_MAX );
        printf ("float min: %e		 max: %e\n", FLT_MIN ,  FLT_MAX );
        printf ("double min: %le 		max: %le\n", DBL_MIN ,  DBL_MAX );
        printf ("long double min: %Le 		max: %Le\n\n", LDBL_MIN ,  LDBL_MAX );
        
        printf("ziarno float: %e\n", FLT_EPSILON);
        printf("ziarno double: %le\n", DBL_EPSILON);
        printf("ziarno long double: %Le\n\n", LDBL_EPSILON);
        
        printf("precyzja float: %e\n", FLT_DIG);
        printf("precyzja double: %le\n", DBL_DIG);
        printf("precyzja long double: %Le\n", LDBL_DIG);
        return 0;
}
