#include <stdio.h>
#include <string.h>

int i, j, m, n, a;
int c[20][20];
char x[15], y[15], b[20][20];

void drukuj(int i,int j)
{
    if(i==0 || j==0)
        return 0;
    if(b[i][j] == '/') //na krzyz
	{
        drukuj(i-1,j-1);
        printf("%c",x[i-1]);
    }
    else if(b[i][j]=='|') //w pionie
        drukuj(i-1,j);
    else //na lewo
        drukuj(i,j-1);
}

void dlugosc()
{
    m=strlen(x);
    n=strlen(y);
    for(i = 0; i <= m; i++)
        c[i][0]=0;
    for(i = 0; i<= n; i++)
        c[0][i]=0;
    for(i = 1; i <= m; i++)
        for(j = 1; j <= n; j++)
		{
            if(x[i-1] == y[j-1])
			{
                c[i][j] = c[i-1][j-1] + 1;
                b[i][j] = '/';
            } 
			else if(c[i-1][j] >= c[i][j-1]) 
			{
                c[i][j] = c[i-1][j];
                b[i][j] = '|';
            } 
			else 
			{
                c[i][j] = c[i][j-1];
                b[i][j] = '-';
            }
        }
    drukuj(m,n);
}
 
int main(void){
    printf("Podaj 1 ciag\n");
    gets(x);
    printf("Podaj 2 ciag\n");
    gets(y);
    printf("Najdluzszy wspolny podciag: \n");
    dlugosc();
    printf("\n");
    return 0;
}
