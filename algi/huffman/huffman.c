#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

struct Node
{
    struct Node *left;
    struct Node *right;
    struct Node *parent;
    int d;
    int f;
    char c;
    char code;
};
int suma3;

int ile(struct Node *huff[])
{
    int i;
    int p=0;
    for(i = 0; i < 100; i++)
	{
        if(huff[i]->f > 0)
            p++;
    }
    return p;
}

void dodaj(struct Node *huff[], struct Node *e, int jest)
{
    int i;
    if(jest==0)
	{
        for(i = 0; i <= 26; i++)
		{
            if(huff[i]->f == -1)
			{
                huff[i] = e;
                return;
            } 
			else if(huff[i]->c == e->c) 
			{
                huff[i]->f++;
                return;
            }
        }
    } 
	else 
	{
        for(i=27;i<100;i++)
		{
            if(huff[i]->f == -1)
			{
                huff[i]=e;
                return;
            }
        }
    }
}

void nowy(struct Node *huff[])
{
    FILE *f = fopen("test.txt", "r");
    char temp;
    int i;
    for(i=0;i<100;i++)
	{
        huff[i] = malloc(sizeof(struct Node));
        huff[i]->c = '1';
        huff[i]->f = -1;
    }
    do 
	{
        temp = fgetc(f);
        if(temp>32)
		{
            struct Node *e = malloc(sizeof(struct Node));
            e->c = temp;
            e->f = 1;
            e->d = 0;
            e->left = e->right = e->parent = NULL;
            dodaj(huff, e, 0);
        }
    }while(temp != EOF);
}

struct Node *min(struct Node *huff[])
{
    int i;
    int p;
    int min = INT_MAX;
    for(i=0;i<100;i++)
	{
        if(huff[i]->d == 0)
		{
            if(huff[i]->f != -1)
			{
                 if(huff[i]->f < min)
				 {
                    min=huff[i]->f;
                    p=i;
                }
            }
        }
    }
    if(min == INT_MAX)
        return huff[0];
    else 
	{
        huff[p]->d = 1;
        return huff[p];
    }
}

void druk(struct Node *huff[])
{
    int i;
    for(i=0;i<100;i++)
        if(huff[i]->f > 0)
            printf("%d. %c: %d\n", i, huff[i]->c, huff[i]->f);
} 

struct Node *huffman(struct Node *huff[])
{
    int i;
    struct Node *x;
    struct Node *y;
    int ko = ile(huff);
    for(i=27;i<27+ko-1;i++)
	{
        x = min(huff);
        //printf("x->f = %d\t\t\t", x->f);
        y = min(huff);
        //printf("y->f = %d \n", y->f);
        struct Node *z = malloc(sizeof(struct Node));
        x->code = '0';
        y->code = '1';
        z->left = x;
        x->parent = z;
        z->right = y;
        y->parent = z;
        z->f = x->f + y->f;
        z->c = 'z';
        //printf("\t\tz->f = %d \n", z->f);
        dodaj(huff,z,1);
    }
    return min(huff);
}

void drukD(struct Node *n, char c[], int lenc)
{
  	if(!(n->left))
  	{
		printf("Kod %c: ", n->c);
  	 	int i;
		int suma2=0;
    	for(i=0;i<lenc;i++)
		{
 			suma2++;
			printf("%c", c[i]);
	    }
	    suma2=suma2*n->f;
 	  	suma3=suma3+suma2;
 	  	printf("\n");
 	} 
	else 
	{
    	c[lenc] = '0';
   		drukD(n->left, c, lenc + 1);
    	c[lenc] = '1';
   		drukD(n->right, c, lenc + 1);
  	}
}

void zlicz(struct Node *h[])
{
	int i;
	int suma=0;
	for(i=0;i<27;i++)
		if(h[i]->f != -1)
			suma = suma + h[i]->f;
	suma=suma*8; //8 bitow na znak
	printf("Przed: %d\nPo: %d \n", suma, suma3);
}

int main()
{
    struct Node *huff[100], *tmp;
    char tab[100];
    suma3=0;
    nowy(huff);
    tmp=huffman(huff);
    druk(huff);
    printf("\n");
    drukD(tmp, tab, 0); //koncowe
    printf("\n");
    zlicz(huff);
    return 0;
}
