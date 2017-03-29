#include <stdio.h>
#include <math.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

void kreski()
{
	printf("---------------------------------------------------------------------------\n");
}

void komunikat()
{
	printf("***Nacisnij ESC aby wyjsc BEZ zapisu lub CTRL+S aby zapisac, a potem ESC***\n\n");
	kreski();
}

int main()
{
	int k=0;
	int i=0; //dlugosc wczytanego
	int j;
	char nazwa[40];
	char txt[20000];
	char temp;
	printf("Jello! Notepad *,...,*\n");
	printf("Podaj nazwe pliku do otwarcia (na przyklad test.txt)\n");
	scanf("%s",&nazwa);
	printf("Otwieranie %s ...\n",nazwa);
	sleep(1);
	system("cls");
	FILE * note = fopen(nazwa, "a+");
	if (note == NULL) 
	{
  	   	printf("Brak pliku %s !\n",nazwa);
  	  	return 0;
 	}
 	komunikat();
 	while(fscanf(note,"%c",&temp)==1)
	{
		txt[i]=temp;
		printf("%c",txt[i]);
		i++;
	}
	fclose(note);
    while(k==0)
    {
    	switch(temp=getch())
    	{
    		case 27: // esc quit
    		k=1;
    		printf("\n");
    		kreski();
    		printf("WYJSCIE");
      		break;
      		
      		case 19: // ctrl+s save
      		printf("");
      		FILE * note = fopen(nazwa, "w+");
    		for(j=0;j<i;j++)
    			fprintf(note,"%c",txt[j]);
    		fclose(note);
    		printf("\n");
    		kreski();
    		printf("\nZAPISANO PLIK %s\n",nazwa);
    		sleep(1);
    		system("cls");
    		komunikat();
 			for(j=0;j<i;j++)
 				printf("%c",txt[j]);
      		break;
      		
      		case 13: // enter
      		txt[i]='\n';
      		printf("%c",txt[i]);
      		i++;
      		break;
      		
      		case 8: // backspace
      		i--;
      		system("cls");
    		komunikat();
 			for(j=0;j<i;j++)
 				printf("%c",txt[j]);
      		break;
      		
      		default:
    		txt[i]=temp;
    		printf("%c",txt[i]);
    		i++;
    		break;
    	}
	}
    fclose(note);
    return 0;
}
