#include <stdio.h>
#include <stdlib.h>

//str 396
//dodajemy argumenty 
//mozna zrobic program z argumentami
int main(int argc, char *argv[]){
  
  int ch;//przechowuje znaki
  FILE *wp; //na plik
  long counter = 0;

  if(argc!=2){
    printf("Sposob  uzycia :%s nazwa_pliku\n",argv[0]);
    exit(1);
  }
  //**Otwarcie pliku z trybem odczytu
  //inne tryby to w r+(uakutalnienie) w+(dodanie do pliku),a moze tworzyc plik jesli
  //nie istnieje rb wb(to tryb binarny)
  if((wp = fopen(argv[1],"r")) == NULL){
    printf("Nie mozna otworzyc %s\n",argv[1]);
    exit(1);
  }

  while((ch = getc(wp))!=EOF){
    putc(ch,stdout); //tego nie trzeba
    counter++;
  }
  fclose(wp);
  printf("Plik %s zawiera %ld znakow\n",argv[1],counter);
  return 0;
}