#include <stdio.h>
#include <stdlib.h>

typedef struct wezel 
{
    int x;
    struct wezel *lewy, *prawy;
} WEZEL;

void wstaw(WEZEL** drzewo, WEZEL *element) 
{
    if (!(*drzewo)) 
	{
        *drzewo = element;
        return;
    }
    else 
	{
        if (element->x < (*drzewo)->x)
            wstaw(&(*drzewo)->lewy, element);
        else
            wstaw(&(*drzewo)->prawy, element);
    }
}

int szukaj(WEZEL *drzewo, int n, int krok) 
{
    if (drzewo) 
	{
        if (drzewo->x == n)
            return krok;
        else {
            if (n < drzewo->x)
                szukaj(drzewo->lewy, n, krok+1);
            else
                szukaj(drzewo->prawy, n, krok+1);
        }
    }
    else 
	{
        return -1;
    }
}

int wysokosc(WEZEL *drzewo) 
{
    int lh, rh;
    if (drzewo == NULL)
        return 0;
    else 
	{
        lh = wysokosc(drzewo->lewy);
        rh = wysokosc(drzewo->prawy);
        return lh < rh ? rh + 1 : lh + 1;
    }
}

int liczmax(WEZEL *drzewo) 
{
    return (abs(wysokosc(drzewo->lewy) - wysokosc(drzewo->prawy)));
}

int main() 
{
    int n,i;
    WEZEL *element, *drzewo;
    drzewo = NULL;
    int ile, x;
    printf("Ile elementow chcesz dodac? ");
    scanf("%d", &ile);
    for(i=0;i<ile;i++) 
	{
        scanf("%d", &n);
        element = (WEZEL*) malloc (sizeof(WEZEL));
        element->lewy = element->prawy = NULL;
        element->x = n;
        wstaw(&drzewo, element);
    }
    printf("Jaki element chcesz znalezc? ");
    scanf("%d", &x);
    if (szukaj(drzewo, x, 0) == -1)
        printf("Nie znaleziono elementu\n");
    else
        printf("Znaleziono element: %d, ilosc krokow: %d\n", x, szukaj(drzewo, x, 0));
    printf("Wysokosc drzewa: %d\n", wysokosc(drzewo));
    printf("Max. roznica wysokosci poddrzew: %d", liczmax(drzewo));
    return 0;
}


