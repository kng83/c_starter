
#include <stdio.h>
#define NAPIS "To jest stala lancuchowa."
#define MAXDL 81

int main(void){
    static char owoce[3][17] = {"banan","kot","pies"};
    static char *cos[] = {"Banaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa","kot","pies","ban","kot","pies","ban","kot","pies"};
    puts("ste");
    printf("\nPorownanie dl  %i i wsk  %i i %c" , sizeof owoce[0], sizeof *cos[0], cos[0][1]);
    //wynik Porownanie dl  17 i wsk  1 i a -- 1 poniewaz char ma dlugosc 1;
    //jak zabierzemy dereferencje to bedziemy miec dlugosc samego wskaznika
    //pod tym wzgledm tablica jest lepsza
}