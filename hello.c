#include <stdio.h>
#include <ctype.h>

#define MAX_STRING 81
void simple(void);
void with_gets(void);
void with_fgets(void);

int main(){
//
with_fgets();
}


void simple(){
    
    char imie[MAX_STRING];
    printf("Podaje imie:\n");
    gets(imie);
    printf("oto twoje imie %s",imie);
}
//wersja ze wskaznikiem
void with_gets(){
    char imie[MAX_STRING];
    char * ptr_imie;
    printf("Podaje imie:\n");
    ptr_imie = gets(imie);//tu jest zwracany wskaznik do imie
    printf("oto twoje imie %s",ptr_imie);

}

// teraz fgets
void with_fgets(){
    char imie[MAX_STRING];
    char * ptr_imie;
    printf("Podaje imie:\n");
    ptr_imie = fgets(imie,MAX_STRING,stdin);//stdin jako wejscie klawiatury
    printf("oto twoje imie %s",ptr_imie);

}
