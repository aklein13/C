#include <time.h>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
int counter;
#define MLD 1000000000.0

void PrintInf();
void SelectionSort(int tablica[], int ile_liczb);
void BubbleSort(int tab[],int n);

int Partition(int A[],int p,int r);
void InsertonSort( int tab[], int size );
void saveName(int tabA[], int heapLength,double Tr,double Tn,double Tw, int flagLos,char sortType[]);
void BuildHeap( int tab[], int heapSize );
void Heapify(int tab[], int heapSize, int ojciec );
void HeapSort( int tab[], int heapSize );
void Swap( int tab[], int a, int b );
void PrintTab( int tab[], int heapSize );
int left(int i){if(i==0)return 1; else return 2*i;};
int right(int i){if(i==0)return 2; else return 2*i+1;};
void CreateRandomTab();
void CreateWriteTab();
int Random(int min, int max);
void Counter();


int main(){		
	
	int flag;													
	int choose2=1;
	int zarodek= time(NULL);
	srand(zarodek);
	struct timespec tp0, tp1,tpr1,tpr2,tpw1,tpw2;
     
   while(choose2!=0){
	 
	 Counter();
	 char output[15] = "output";
	 char number[3];
	 sprintf(number,"%d",counter);
	 strcat(output,number);
	 strcat(output,".txt");
	
	
	
	one:
	system("cls");
    printf("\n==========================================================\n"); 
    printf("			SORTEST                          ");
    printf("\n\n Menu:");
    printf("\n (1) Sortowanie losowo generowanej tablicy");
    printf("\n (2) Sortowanie tablicy wpisanej z klawiatury");
    printf("\n (3) Sortowanie tablicy z pliku input.txt(Ostatnie sortowanie)");
    printf("\n (4) Informacje o programie");
    
   
    
	int choose;
	int choose3;
	
	while(choose3!=1){
		printf("\n Wybor: ");
		
		scanf("%d",&choose);
		
		
		switch (choose){
			case 1:
				clock_gettime(CLOCK_PROCESS_CPUTIME_ID,&tpr1);
				CreateRandomTab();
				clock_gettime(CLOCK_PROCESS_CPUTIME_ID,&tpr2);
				flag = 1;
				choose3=1;
				break;
			case 2:
				CreateWriteTab();
				choose3=1;
				flag = 0;
				break;
			case 3:
				choose3=1;
				flag = 0;
				break;
			case 4:
				PrintInf();
				flag = 0;
				getch();
				goto one;
				break;
			default:
				choose3=1;
				printf("\nPodana wartosc jest bledna!");
	   }
}
	choose3=0;
	system("cls");
	clock_gettime(CLOCK_PROCESS_CPUTIME_ID,&tpw1);
    int heapLength=0;
    int temp;  
    FILE *fp;                          
	if((fp=fopen("input.txt","r"))==NULL)
		printf("Nie udalo sie otworzyc pliku do odczytu");                 
	else{
		while(fscanf(fp,"%d",&temp)!=EOF)
		heapLength++;
	}
	int tabA[heapLength];
	rewind(fp);
	for(temp=0;temp<(heapLength);temp++)
		fscanf(fp,"%d",&tabA[temp]);
	fclose(fp);
	
	printf("Z pliku odczytano tablice:\n");
	PrintTab(tabA,heapLength);
	printf("\n");
	int chooseSortCheck=1;
	int chooseSort = 0;
	char sortType[20]="";
	printf("\nSposob sortowania: \n(1) insertion sort \n(2) heap sort\n(3) kwak sort\n(4) bubble sort\n(5) selection sort\n");
	while(chooseSortCheck==1){
		printf("\nWybor: ");
		scanf("%d",&chooseSort);
		switch(chooseSort){
			case 1:
				strcat(sortType,"InsertionSort");
				clock_gettime(CLOCK_PROCESS_CPUTIME_ID,&tp0);
				InsertonSort(tabA,heapLength);
				clock_gettime(CLOCK_PROCESS_CPUTIME_ID,&tp1);
				chooseSortCheck=0;
				break;
		
			case 2: 
				strcat(sortType,"HeapSort");
				clock_gettime(CLOCK_PROCESS_CPUTIME_ID,&tp0);
				HeapSort(tabA,heapLength);
				clock_gettime(CLOCK_PROCESS_CPUTIME_ID,&tp1);
				chooseSortCheck=0;
				break;
			case 3:
				
				clock_gettime(CLOCK_PROCESS_CPUTIME_ID,&tp0);
				
				clock_gettime(CLOCK_PROCESS_CPUTIME_ID,&tp1);
				chooseSortCheck=0;
				break;
			case 4: 
				strcat(sortType,"BubbleSort");
				clock_gettime(CLOCK_PROCESS_CPUTIME_ID,&tp0);
				BubbleSort(tabA,heapLength);
				clock_gettime(CLOCK_PROCESS_CPUTIME_ID,&tp1);
				chooseSortCheck=0;
				break;
			case 5:
				strcat(sortType,"SelectionSort");
				clock_gettime(CLOCK_PROCESS_CPUTIME_ID,&tp0);
				SelectionSort(tabA,heapLength);
				clock_gettime(CLOCK_PROCESS_CPUTIME_ID,&tp1);
				chooseSortCheck=0;
				break;
			default:
				printf("\nPodana bledna warosc.");
				chooseSortCheck=1;
				break;
	}
}
	printf("\n");
	system("cls");
	printf("Posortowana tablica zapisana do pliku:\n");
	PrintTab(tabA,heapLength);
	
	double Tn=(tp1.tv_sec+tp1.tv_nsec/MLD)-(tp0.tv_sec+tp0.tv_nsec/MLD);
	double Tr=(tpr2.tv_sec+tpr2.tv_nsec/MLD)-(tpr1.tv_sec+tpr1.tv_nsec/MLD);
	clock_gettime(CLOCK_PROCESS_CPUTIME_ID,&tpw2);
	double Tw=((tpw2.tv_sec+tpw2.tv_nsec/MLD)-(tpw1.tv_sec+tpw1.tv_nsec/MLD))-Tn-Tr;

	if(flag==1)printf("\n\n\n\n>Losowanie liczb zajelo: %3.5lf sekund.\n", Tr);
	printf("\n>Sortowanie %d elementow metoda %s zajelo %3.5lf sekund.\n", heapLength, sortType,Tn);
	if(flag==1)printf("\n>Reszta procesow zajela %3.5lf sekund.\n",Tw);
	
	saveName(tabA,heapLength,Tr,Tn,Tw,flag,sortType);

	printf("\n\n\n(1)Wroc do menu \n(0)Wylacz program\n");
	scanf("%d",&choose2);
}
return 0;
}
void PrintInf(){
	system("cls");
				printf("deus non vult");
	}
void Swap (int tab[], int a, int b){//zamienia elementy tablicy miejscami
	int x;
	x=tab[a];
	tab[a]=tab[b];
	tab[b]=x;
}
void SelectionSort(int tablica[], int ile_liczb){
int min,i,j,temp;
for (i=0;i<ile_liczb-1;i++){
	min=i;
	for (j=i+1;j<ile_liczb;j++)
	if (tablica[j]<tablica[min]) min=j;
	temp=tablica[min];
	tablica[min]=tablica[i];
	tablica[i]=temp;
	}
}
void BubbleSort(int tab[],int n){
  for(int i=0;i<n;i++)
    for(int j=1;j<n-i;j++)
		if(tab[j-1]>tab[j]) Swap(tab,(j-1),j);
}

void saveName(int tabA[], int heapLength,double Tr,double Tn,double Tw, int flagLos,char sortType[]){
	char outputSpec[20]="";
	strcat(outputSpec,sortType);
	FILE *fp;
	int choose4,flagSave=0; char number[3];
	char nameUser[20];char nameUserSpec[20]="";
	printf("\nZapis: \n(1) automatycznie \n(2) wlasna nazwa \n(3) nie zapisuj\nWybor: ");
	scanf("%d",&choose4);
	switch(choose4){
		case 1: 
			sprintf(number,"%d",counter);
			strcat(sortType,number);
			strcat(sortType,".txt");
			break;
		strcat(outputSpec,number);
		 strcat(outputSpec,"_spec");
		 strcat(outputSpec,".txt");
			
		case 2:
			printf("Nazwa: ");
			scanf("%s",nameUser);
			strcat(nameUserSpec, nameUser);
			strcat(nameUserSpec,"_spec.txt");
			strcat(nameUser,".txt");
			flagSave = 1;
			break;
		case 3:
			flagSave=2;
			break;
	}
		
	 switch(flagSave){
		 case 0: 
		 

		 
		 if((fp=fopen(sortType,"w"))==NULL)
			printf("Nie udalo sie otworzyc pliku do zapisu");
		 
		 else
			for(int temp=0;temp<heapLength;temp++)
				fprintf(fp,"%d \n",tabA[temp]);
		fclose(fp);	
		 if((fp=fopen(sortType,"w"))==NULL)
			printf("Nie udalo sie otworzyc pliku do zapisu");
		 
		 else
			for(int temp=0;temp<heapLength;temp++)
				fprintf(fp,"%d \n",tabA[temp]);
		
		fclose(fp);
		
			
		strcat(outputSpec,number);
		strcat(outputSpec,"_spec.txt");
		
		 if((fp=fopen(outputSpec,"w"))==NULL)
			printf("Nie udalo sie otworzyc pliku do zapisu");
		 
		 else{
			//if(flagLos==1)fprintf(fp,"\nIlosc losowanych liczb: %d",heapLength);
			if(flagLos==1)fprintf(fp,"\n\n\n\n>Losowanie %d liczb zajelo: %3.5lf sekund.\n",heapLength,Tr); 
			fprintf(fp,"\n>Sortowanie zajelo %3.5lf sekund.\n", Tn);
			if(flagLos==1)fprintf(fp,"\n>Reszta procesow zajela %3.5lf sekund.\n",Tw);
			}
		fclose(fp);
		system("cls");
		printf("\n>Posortowane liczby zostaly zapisane do pliku %s\n",sortType);
		printf("\n>Czas wykonania i ilosc sortowanych liczb zostaly zapisane do pliku %s",outputSpec);
		break;
	case 1:  
		 if((fp=fopen(nameUser,"w"))==NULL)
			printf("Nie udalo sie otworzyc pliku do zapisu");
		 
		 else
			for(int temp=0;temp<heapLength;temp++)
				fprintf(fp,"%d \n",tabA[temp]);
		fclose(fp);	
		 if((fp=fopen(nameUser,"w"))==NULL)
			printf("Nie udalo sie otworzyc pliku do zapisu");
		 
		 else
			for(int temp=0;temp<heapLength;temp++)
				fprintf(fp,"%d \n",tabA[temp]);
		
		fclose(fp);
		if((fp=fopen(nameUserSpec,"w"))==NULL)
			printf("Nie udalo sie otworzyc pliku do zapisu");
		 
		 else{
			if(flagLos==1)fprintf(fp,"\nIlosc losowanych liczb: %d",heapLength);
			if(flagLos==1)fprintf(fp,"\n\n\n\n>Losowanie liczb zajelo: %3.5lf sekund.\n", Tr); 
			fprintf(fp,"\n>Sortowanie zajelo %3.5lf sekund.\n", Tn);
			if(flagLos==1)fprintf(fp,"\n>Reszta procesow zajela %3.5lf sekund.\n",Tw);
			}
		fclose(fp);
		system("cls");
		printf("\n>Posortowane liczby zostaly zapisane do pliku %s\n",nameUser);
		printf("\n>Czas wykonania i ilosc sortowanych liczb zostaly zapisane do pliku %s",nameUserSpec);
		break;

	case 2:
	break;
	}
}
void InsertonSort( int tab[], int size ){
    int temp, j;
    
    for( int i = 1; i < size; i++ )
    {
        temp = tab[ i ];
        
        for( j = i - 1; j >= 0 && tab[ j ] > temp; j-- )
             tab[ j + 1 ] = tab[ j ];
        
        tab[ j + 1 ] = temp;
    }
}														
void BuildHeap(int t[], int rozmiar){ 
 int i;
 for (i=rozmiar/2; i>=0; --i) 
    Heapify(t,i,rozmiar);
}
void HeapSort(int tab[],int rozmiar){
 BuildHeap(tab,rozmiar); //zbuduj kopiec
 int n=rozmiar; 
 for (int i=rozmiar-1; i>=1; --i){ //tyle razy ile jest elementow-1 (bo ostatniego nei trzeba)  
    Swap(tab,i,0); // zamien ostatni z pierwszym
    --n; // zmniejsz heapsize
    Heapify(tab,0,n); //sprawdz wszystko
 }
}
void Heapify(int tab[], int i, int n){  // ITERACYJNIE 		i-ojciec, n =rozmiar	
	

   while (i <= n){
	 int largest;
	 int l = left(i); //   dla i=0 l = 1, inaczej 2*i
	 int r = right(i);//  dla i=0 p=2, inazcej 2*i+1
	 
	 if (l<n && tab[l] > tab[i]) // jesli pozycja lewego jest w zakresie  i  jego wartosc jest wieksza od ojca to
		largest = l; // lewy jest najwiekszy
	 else //w innym wypadku
		largest = i; // ojciec jest najwiekszy
	 
	 if (r< n && tab[r] > tab[largest]) // jesli pozycja prawego jest w zakresie i jego wartosc jest wieksza od najwiekszego (lewego lub ojca) 
		largest = r; //  prawy jest najwiekszy

	 if (largest != i){ //jesli ojciec nie jest najwiekszy
		Swap(tab,i,largest); // zamien ojca i wiekszego syna
		i=largest; //najwiekszy jest nowym ojciec 
	 } 
	 else
		break;
}
}
void PrintTab( int tab[], int heapSize ){ // drukuje tablice na ekranie
    int i;
    for(i=0;i<heapSize;i++)
		printf(" %i ",tab[i]);
    printf("\n");
}
int Random(int min, int max){ // losuje liczby z zakresu
    int tmp;
    if (max>=min)
        max-= min;
    else
    {
        tmp= min - max;
        min= max;
        max= tmp;
    }
    return max ? (rand() % max + min) : min;
}
void CreateRandomTab(){	//losuje dana ilosc randomowych liczb  zapisuje je w pliku input.txt	
	
	FILE *fp;
	int iloscElement;
	int maxElement;
	int minElement;
	printf("\nIlosc elementow wygenerowanej losowo tablicy: ");
	scanf("%d",&iloscElement);
	printf("\nZakres dolny: ");
	scanf("%d",&minElement);
	printf("Zakres gorny: ");
	scanf("%d",&maxElement);
	
	
	 if((fp=fopen("input.txt","w"))==NULL)
	printf("Nie udalo sie otworzyc pliku do zapisu");
 
 else
	for(int i=0;i<iloscElement;i++){
		int los = Random(minElement,maxElement+1);
		fprintf(fp,"%d \n",los);
	}
	fclose(fp);
}
void CreateWriteTab(){ // tworzy tablice z reki i zapisuje w input.txt
	
	FILE *fp;
	printf("\nIlosc elementow tablicy: ");
	int tabSize;
	scanf("%d",&tabSize);
	int tab[tabSize];

	for(int i = 0; i < tabSize; i++){
		printf("Element tablicy nr %d: ",i+1);
		scanf("%d",&tab[i]);
	}
	
	if((fp=fopen("input.txt","w"))==NULL)
		printf("Nie udalo sie otworzyc pliku do zapisu");
	else
		for(int i=0;i<tabSize;i++){
		fprintf(fp,"%d \n",tab[i]);
		}
	fclose(fp);
	}
void Counter(){
					
	FILE *fp;  
	
	if((fp=fopen("counter.txt","r"))==NULL)
		printf("Nie udalo sie otworzyc pliku do odczytu");                 
	else{
		
		fscanf(fp,"%d",&counter);
	fclose(fp);
	}
		if((fp=fopen("counter.txt","w"))==NULL)
		printf("Nie udalo sie otworzyc pliku do zapisu");
	 
	 else
			fprintf(fp,"%d \n",counter+1);
	fclose(fp);
}
