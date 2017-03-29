#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define RED 1        /* stala oznaczajaca kolor wezla */
#define BLACK 0      /* stala oznaczajaca kolor wezla */
#define SZER_EKR 80  /* szerokosc ekranu */
#define IL_POZ   5   /* ilosc poziomow drzewa, ktore beda wydrukowane   */
                     /* gwiazdka bedzie sygnalizowac istnienie nizszych */
                     /* poziomow                                        */

/* struktury danych do reprezentowania drzewa */
typedef struct wezel *Wskwezla; /* wskaznik na wezel drzewa  */
typedef struct wezel{
	int klucz;
	Wskwezla left, right, p;
	int kolor;
} Twezla ;  /* typ wezla */

/* drzewa z wartownikami: wezel wskazywany przez "nil" jest wartownikiem 
   zastepujacym NULL; dla korzenia pole "p" ma wartosc "nil"; 
   pole nil->p musi byc ustawione odpowiednio w przy usuwaniu 
*/
Wskwezla nil; 

void nilInit(void){
/* funkcja inicjujaca nil; musi byc wywolana przed budowaniem drzewa */
  nil= (Wskwezla) malloc(sizeof(Twezla));
  nil->p = NULL;
  nil->kolor = BLACK;
  nil->left = nil->right = NULL;  
}

void drukuj(Wskwezla w);
/* funkcja drukujaca drzewo binarne na ekranie (tutaj tylko deklaracja) */
/* funkcja drukuje drzewo o korzeniu "w"                                */

void drukujDot(Wskwezla r);
  // generuje w plikach drzewo0.gv,  drzewo1.gv ...
  // opis drzew o korzeniu r do wydrukowania przez program dot
  // zlecenie "dot -Tpdf -O drzewo1.gv" utworzy plik "drzewo1.gv.pdf" 

/* ------------  implementacja ------------------------------------- */
char wydruk[IL_POZ+1][SZER_EKR];

void drukujost(Wskwezla w, int l, int p,int poziom){
       int srodek = (l+p)/2;
       if (w==nil)   return; 
       wydruk[poziom][srodek]='*';
}

void drukujwew(Wskwezla w, int l, int p,int poziom){
       int srodek = (l+p)/2;
       int i,dl;
       char s[19];
       if (w==nil)    return;
       if (w->kolor==BLACK)
         dl=sprintf(s,"%d",w->klucz);
       else
	 //	        dl=sprintf(s,"\e[31m%+d\e[0m",w->klucz);
       dl=sprintf(s,"%+d",w->klucz);
       for (i=0;i<dl;i++)
         wydruk[poziom][srodek-dl/2+i]=s[i];
       if (++poziom<IL_POZ){
         drukujwew(w->left,l,srodek,poziom) ;
         drukujwew(w->right,srodek+1,p,poziom) ;
       }
       else {
         drukujost(w->left,l,srodek,poziom) ;
         drukujost(w->right,srodek+1,p,poziom) ;
       }
}

void drukuj(Wskwezla w){
  int j,i;
  for (i=0;i<=IL_POZ;i++)
    for (j=0;j<SZER_EKR;j++)
      wydruk[i][j] = ' ';
  drukujwew(w,0,SZER_EKR,0);
  for (i=0;i<=IL_POZ;i++){
      for (j=0;j<SZER_EKR;j++)
        putchar(wydruk[i][j]);
      printf("\n");
  }
}

void drukujKrawedz(FILE *plikwy, Wskwezla r, int z, Wskwezla syn, int zs){
// wezel r o numerze z jest juz wydrukowany
// teraz drukujemy jego syna "syn" o numerze zs oraz krawedz miedzy nimi
  if (syn == nil){
    fprintf(plikwy,"%d [shape=circle, style=invisible, label=\"",zs);
    fprintf(plikwy,"%d ",0);
    fprintf(plikwy,"\"]\n");
    fprintf(plikwy,"%d -- %d [style=invis];\n ",z,zs);
  } else{
    if (syn->kolor == RED)
      fprintf(plikwy,"%d [shape=circle, color=red, label=\"",zs);
    else
      fprintf(plikwy,"%d [shape=circle, color=black, label=\"",zs);
    fprintf(plikwy,"%d ",syn->klucz);
    fprintf(plikwy,"\"]\n");
    fprintf(plikwy,"%d -- %d ;\n",z,zs);
  }  
}

int rekDrukujDot(Wskwezla r, int z, FILE *plikwy){
  // drukuje drzewo o korzeniu r 
  // z  - numer wezla r
  // zwraca najwiekszy numer wezla w poddrzewie, ktorego jest korzeniem
  // zakladamy, ze korzen r jest juz wydrukowany
  int nz;
  if (r == nil) return z;
  else{
    drukujKrawedz(plikwy,r,z,r->left,z+1);
    nz=rekDrukujDot(r->left,z+1,plikwy);
    drukujKrawedz(plikwy,r,z,r->right,nz+1);
    nz=rekDrukujDot(r->right,nz+1,plikwy);
    return nz;
  }
}

void drukujDot(Wskwezla r){
  // generuje w plikach drzewo0.gv, dzrewo1.gv, ... 
  // opisy drzew o korzeniu r pzeznaczone do wydrukowania przez program dot
  // zlecenie "dot -Tpdf -O drzewo1.gv" utworzy plik "drzewo1.gv.pdf" 
  static int gdzie=0;
  char numer[10];
  char nazwap[20]="drzewo";
  FILE *plikwy;
  snprintf(numer,9,"%d",gdzie);
  strcat(nazwap,numer);
  strcat(nazwap,".gv");
  plikwy=fopen(nazwap,"w");
  gdzie++;
  fprintf(plikwy, "graph drzewo{\n");
  fprintf(plikwy, "size = \"2,20\"");
  if (r!=nil){
    if (r->kolor == RED)
      fprintf(plikwy,"%d [shape=circle, color=red, label=\"",0);
    else
      fprintf(plikwy,"%d [shape=circle, color=black, label=\"",0);
    fprintf(plikwy,"%d ",r->klucz);
    fprintf(plikwy,"\"]\n");
    rekDrukujDot(r,0,plikwy);
  }
  fprintf(plikwy, "}\n");
  fclose(plikwy);
  printf("Wydrukowane %s\n",nazwap);
}

////////////

void RL(Wskwezla *k,Wskwezla x) //rotate
{
	Wskwezla y = x->right;
	x->right = y->left;
	if(y->left != nil)
		y->left->p = x;
	y->p = x->p;
	if(x->p  == nil)
        (*k) = y;
	else if(x == x->p->left)
        x->p->left = y;
	else
        x->p->right = y;
	y->left = x;
	x->p = y;
}

void RR(Wskwezla *k,Wskwezla x)
{
	Wskwezla y = x->left;
	x->left = y->right;
	if(y->right != nil)
		y->right->p = x;
	y->p = x->p;
	if(x->p == nil)
        (*k)=y;
	else if(x == x->p->right)
        x->p->right = y;
	else 
	    x->p->left = y;
	y->right = x;
	x->p = y;
}

Wskwezla Wstaw(Wskwezla *k, int kluczz)
{
	Wskwezla g = malloc(sizeof(Twezla));
	g->p = nil;
	g->klucz = kluczz;
	g->left = nil;
	g->right = nil;
	Wskwezla y = nil;
	Wskwezla x = *k;
	while( x!=nil)
	{
		y=x;
		if(g->klucz<x->klucz)
			x=x->left;
		else
			x=x->right;
	}
	g->p = y;
	if(y == nil)
	    *k=g;
	else if(g->klucz<y->klucz)
		y->left = g;
	 else
		y->right = g;
	return g;
}

void RBinsert(Wskwezla *k, int klucz)
{
	Wskwezla x = Wstaw(k,klucz);
	x->kolor = RED;
	while(x->p->kolor == RED)
	{
		if(x->p==x->p->p->left)
		{
			Wskwezla y = x->p->p->right;
			if(y->kolor == RED)
			{
				x->p->kolor = BLACK;
				y->kolor = BLACK;
				x->p->p->kolor = RED;
				x = x->p->p;
			} 
			else 
			{
				if(x == x->p->right)
				{
					x = x->p;
					RL(k, x);
				}
				x->p->kolor = BLACK;
				x->p->p->kolor = RED;
				RR(k, x->p->p); //rotate
			}
		} 
		else 
		{
			Wskwezla y = x->p->p->left;
			if(y->kolor == RED)
			{
				x->p->kolor = BLACK;
				y->kolor = BLACK;
				x->p->p->kolor = RED;
				x = x->p->p;
			} 
			else 
			{
				if(x == x->p->left)
				{
					x = x->p;
					RR(k, x);
				}
				x->p->kolor = BLACK;
				x->p->p->kolor = RED;
				RL(k, x->p->p);
			}
		}
	}
	(*k)->kolor = BLACK;
}

int czerw(Wskwezla T) //liczy czeerwone
{
    static int czer; //static zeby wartosc sie nie zmieniala przy powtorzeniach
	if(T != nil)
	{
		czerw(T->left);
		if(T->kolor == RED)
		    czer++;
		czerw(T->right);
	}
    return czer;
}

int hMax(Wskwezla T)
{
	int wys1;
	int wys2;
	if(T != nil)
	{
		wys1 = hMax(T->left);
		wys2 = hMax(T->right);
		if(wys1 > wys2)
            return wys1 + 1;
		else
            return wys2 + 1;
    } 
	else 
        return 0;
}

int hMin(Wskwezla T)
{
    int wys1;
    int wys2;
    if(T == nil)
        return 0;
    if(T->left == nil)
        return hMin(T->right) + 1;
    if(T->right == nil)
        return hMin(T->left) + 1;
    wys1 = hMin(T->right);
    wys2 = hMin(T->left);
    if(wys1 > wys2)
        return wys2 + 1;
    else
        return wys1 + 1;
}
   /* Przyklad: [8 elementow, 4 czerwone, max:4, min:2] [wstaw: 2,1,4,5,9,3,6,7]
   
             2
            / \
           1   +5 
              / \
             4   7
            /	/ \
           +3  +6 +9	
		   				*/
int main()
{
    nilInit();
    int c,i,x;
    Wskwezla korzen=nil;
    printf("Podaj wyrazy drzewa do wstawienia\n");
    for(i=0;i<8;i++)
	{
        scanf("%d",&x);
        RBinsert(&korzen, x);
   		drukuj(korzen);
   		printf("----------------------------------------------------------------------\n");
    }
    drukuj(korzen);
    //drukujDot(korzen);
    c=czerw(korzen);
    printf("Ilosc czerwonych: %i \n",c);
    printf("Max glebokosc: %i \n",hMax(korzen));
    printf("Min glebokosc: %i",hMin(korzen));
    return 0;
}

     




