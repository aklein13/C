#include <stdio.h>
 
void main()
{
    int i,j,s,k; // i,j - zmienne petli
     printf("\t");
    for(i=1;i<=10;i++){
        printf("%d\t", i);}
        
    for(i=1;i<=10;i++)
    {
        printf("\n%d\t",i);
        for(j=1;j<=10;j++)
        {
        	for(k=0;k<j;k++) //petla dodajaca (zastepuje mnozenie)
        	{
        		s=s+i;
			}
            printf("%d\t",s);
            s=0;
        }
    }
}
