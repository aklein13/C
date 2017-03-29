#include <stdio.h>
#include <limits.h>
#include <float.h>
 
int main()
{
    int a;
    int b;
    double c;
    a=FLT_MAX;
    b=DBL_MAX;
    c=LDBL_MAX;
    printf("float max do int: %d\n",a);
    printf("double max do int: %d\n",b);
    printf("long double max do double: %le\n",c);
        return 0;
}
