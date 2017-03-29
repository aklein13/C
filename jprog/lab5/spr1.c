#include <stdio.h>
#include <math.h>

typedef struct
{
	int a,b;
}	punkt;

float dlugosc(punkt p0, punkt p1)
{
	float dl;
	dl=sqrt(pow((p1.a-p0.a),2)+pow((p1.b-p0.b),2));
	return dl;
}

double obwod(punkt p0, punkt p1, punkt p2)
{
	float dl1,dl2,dl3;
	dl1=dlugosc(p0,p1);
	dl2=dlugosc(p0,p2);
	dl3=dlugosc(p1,p2);
	double suma;
	suma=dl1+dl2+dl3;
	return suma;
}

int main()
{
	punkt p0,p1,p2;
	int dlu, i;
	printf("Podaj wspolrzedne (x,y) punktu 1\n");
	scanf("%d",&p0.a);
	scanf("%d",&p0.b);
	printf("Podaj wspolrzedne (x,y) punktu 2\n");
	scanf("%d",&p1.a);
	scanf("%d",&p1.b);
	dlu=dlugosc(p0,p1);
	printf("Dlugosc miedzy punktami wynosi: %.6d\nObliczanie obowdu trojkata.\n",dlu);
	printf("Podaj wspolrzedne (x,y) punktu 1\n");
	scanf("%d",&p0.a);
	scanf("%d",&p0.b);
	printf("Podaj wspolrzedne (x,y) punktu 2\n");
	scanf("%d",&p1.a);
	scanf("%d",&p1.b);
	printf("Podaj wspolrzedne (x,y) punktu 3\n");
	scanf("%d",&p2.a);
	scanf("%d",&p2.b);
	float ob;
	ob=obwod(p0,p1,p2);
	printf("Obrwod trojkata wynosi: %5.3f\n",ob);
}
