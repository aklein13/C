#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct {
  int id;
  char nazwa[20];
  int cena;
} przedmiot;

  char nazwa[20];
  int wzrost;
  char bron[16];
  int poziom;
  int ile_przedmiotow;


  void czytanie(char *fileName)
  {
    FILE* stream = fopen(fileName, "r");

    if (stream == NULL) {
      printf("\n Blad podczas proby otwarcia pliku.\n\n");
    }

    fscanf(stream, "%s", nazwa);
    fscanf(stream, "%d", &wzrost);
    fscanf(stream, "%s", bron);
    fscanf(stream, "%d", &poziom);
    fscanf(stream, "%d", &ile_przedmiotow);

    przedmiot array[ile_przedmiotow];

    int i = 0;
    while (fgetc(stream) != EOF) {
      fscanf(stream, "%d", &array[i].id);
      fscanf(stream, "%s", array[i].nazwa);
      fscanf(stream, "%d", &array[i].cena);
      i++;
    }
    fclose(stream);

    // Just to make sure, that it works.
    for(i = 0; i < ile_przedmiotow; i++)
    {
      printf("%s \n", array[i].nazwa);
    }

};

int main (int arg_num, char* arg[]) {

  if (arg_num == 2) {
    czytanie(arg[1]);// wywołanie funkcji czytanie
  }
  else
  printf("\n Poprawne wywolanie: './wczytaj nazwa_pliku'\n\n");

  return 0;
}
