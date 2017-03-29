#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>

#define MAX 18

typedef struct przedmiot {
        int nr_katalogowy;
        char name[MAX];
        float cena;
        struct przedmiot* dalej;
}* lista;

//=======================================================

lista dodaj(int numer, char nazw[MAX], float cen, lista my_list) {
   lista pom;
   pom = (struct przedmiot*) malloc(sizeof(struct przedmiot));
   pom->nr_katalogowy=numer;
   strcpy(pom->name,nazw);
   pom->cena=cen;
   pom->dalej=my_list;
   return pom;
}

//=======================================================

lista  katalog(lista my_list) {
  char nazw[MAX];
  int numer,i;
  float cen;

  FILE* baza = fopen("./lista_przedmiotow","r");
  if (baza == NULL) printf("\n ZLE\n\n");
  for (i=0; i<MAX; i++) 
  {
    fscanf(baza, "%i", &numer);
    fscanf(baza, "%s", nazw);
    fscanf(baza, "%f", &cen);
    my_list=dodaj(numer,nazw,cen,my_list);
  }
  fclose(baza);
  return my_list;
  
}

//=======================================================  
//Napisac funkcje, ktora liczy koszt itemow dla podanego id i zwraca INT

int koszt(lista my_list, int id)
{
	int price;
	lista pom = my_list;
	while(pom != NULL)
	{
		if (pom->nr_katalogowy == id)
		{
			price = pom->cena;
		}
		pom=pom->dalej;
	}
	return price;
}

//=======================================================

void druk(lista my_list) 
{
	lista wynik = my_list;
	while(wynik!=NULL)
	{
		printf("%s \n",wynik->name);
		wynik=wynik->dalej;
	} 
}

int main(){
lista my_list=NULL;
int id, i;
int suma = 0;
my_list=katalog(my_list);
printf("Wpisano:\n");
druk(my_list);
for(i=0;i<3;i++)
{
	printf("Podaj id przedmiotu %d\n",i+1);
	scanf("%d",&id);
	suma = suma + koszt(my_list,id);
}
printf("Suma 3 przedmiotow wynosi: %d\n",suma);
return 0;
}
