#include <stdio.h>
#include <stdlib.h>
#define MAX 40
//dodajemy argumenty 
//mozna zrobic program z argumentami
int main(){
  
    FILE *wp; //na plik
    char slowa[MAX];

    if((wp = fopen("words","a+")) == NULL){
      fprintf(stdin,"Nie moge otworzyc pliku \" words \".\n");
      exit(1);
    }

    puts("Podaj slowa do wpisania do pliku");
    puts("Aby zakonczyc ,wcisnij Enter na poczatku wiersza.");

    while(gets(slowa) != NULL && slowa[0] != '\0')
      fprintf(wp,"\n%s", slowa);
    
    puts("Zawartosc pliku:");
    rewind(wp); // wraca do poczatku pliku

    while(fscanf(wp,"%s",slowa) ==1)
      puts(slowa);
    
    if(fclose(wp)!= 0 )
      fprintf(stderr,"Blad przy zamykaniu pliku.\n");
    return 0;
     
}
