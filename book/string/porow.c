/* porown.c -- to dziala */
#include <stdio.h>
#include <string.h> /* deklaruje strcmp() */
#include<ctype.h>
#define ODPOWIEDZ "Grant"
#define MAX 40

char *wczytaj(char *z, int ile);

int main(void)
{
    char proba[MAX];
    char jakas[MAX] ="kot i olcha";
    char *cos;
    cos = jakas;
    puts("Kto jest pochowany w grobowcu Granta?");
    while (strcmp(proba, ODPOWIEDZ) != 0)
    {
       
        cos=  wczytaj(proba, MAX);
        while(*cos) {
            if(*cos !='\n' && *cos!='\0'){
            putchar(*cos);
            putchar(*cos); //podwojne
            *cos++;
            }
        }
         puts("");
         puts("Niestety to nie jest dobra odpowiedz. Sprobuj jeszcze raz.");
    }
    puts("Tak jest!");
    return 0;
   
}

char *wczytaj(char *z, int ile){
    char *wynik , *inner;
    int i = 0;
    wynik = fgets(z, ile, stdin);
    //daje inner bo inner bedzie tu inkrementowany jak wynik to na zew bedzie mial inny aders
    inner = wynik; 

    // printf("to jest wynik %c %c %c\n",wynik[0],wynik[1],wynik[2]);
    //tak mozna caly wynik wyswietlic
    while(*inner){
        putchar(*inner);
        *inner++; //inner jest inkrementowany dlatego go nie zwracam
    }
    if (wynik) // wynik rozny od NULL
    {
        while (z[i] != '\n' && z[i] != '\0')
            i++;
        if (z[i] == '\n') // znak nowego wiersza -> znak pusty
            z[i] = '\0';  // z[i] == '\0'
        else             
            while (getchar() != '\n')
                continue;
    }
    return wynik;
}