#include <stdio.h>
 
main()
{
    int i,n;
    int il=10;
    printf("\t");
    for (i=1; i<=il; i++)
        printf("%d\t",i);

    for (i=1; i<=il; i++)
    {
        printf("\n%d\t",i);
        for (n=1; n<=il; n++)
        {
            printf("%d\t",n*i);
        }
    }
}
