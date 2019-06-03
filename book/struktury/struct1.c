/* ksiazka.c -- spis jednej ksiazki */
#include <stdio.h>
#include <string.h>
char *wczytaj(char *z, int ile);
#define MAXTYT 41 /* maksymalna dlugosc tytulu + 1 */
#define MAXAUT 31 /* maksymalna dlugosc nazwiska autora + 1 */
struct ksiazka
{ /* szablon struktury o nazwie "ksiazka" */
    char tytul[MAXTYT];
    char autor[MAXAUT];
    float wartosc;
}; /* koniec szablonu struktury */
int main(void)
{
    struct ksiazka bibl; /* deklaracja bibl jako zmiennej typu ksiazka */
    printf("Podaj tytul ksiazki.\n");
    wczytaj(bibl.tytul, MAXTYT); /* dostep do skladnika "tytul" */
    printf("Teraz podaj autora.\n");
    wczytaj(bibl.autor, MAXAUT);
    printf("Teraz podaj wartosc.\n");
    scanf("%f", &bibl.wartosc);
    printf("%s, autor: %s, cena: %.2f zl\n", bibl.tytul, bibl.autor, bibl.wartosc);
    printf("%s: \"%s\" (%.2f zl)\n", bibl.autor,
           bibl.tytul, bibl.wartosc);
    printf("Gotowe.\n");
    return 0;
}
char *wczytaj(char *z, int ile)
{
    char *wynik;
    char *tutaj;
    wynik = fgets(z, ile, stdin);
    if (wynik)
    {
        tutaj = strchr(z, '\n'); // szukamy nowego wiersza
        if (tutaj)               // jesli adres jest rozny od NULL
            *tutaj = '\0';       // zamieniamy znak nowego wiersza na pusty
        else
            while (getchar() != '\n')
                continue;
    }
    return wynik;
}

/*
Z punktu widzenia komputera deklaracja
struct ksiazka bibl;
jest skróconą formą deklaracji
ksiazka jest tu etykieta nie musi jej byc
struct ksiazka {
 char tytul[MAXTYT];
 char autor[MAXAUT];
 float wartosc;
} bibl; //po deklaracji nastepuje nazwa zmiennej 

//struktrua zainicjalizowana
struct book bibl = {
 "Pirat i dziewica",
 "Rene Vivotte",
 7.95
};

//w c99 mozna tak zainicjalizowac strukture
//piszemy kropke i wartosc
struct ksiazka prezent = { 
 .wartosc = 25.99,
 .autor = "Adam Mickiewicz",
 .tytul = "Pan Tadeusz"};
*/

/*
Przykład:
struct {
 int kod;
 float cena;
} artykul, * wskst;
wskst = &artykul;
wskst->kod = 3451;
Ostatnia instrukcja nadaje wartość składnikowi kod struktury artykul. Poniższe
trzy wyrażenia są równoważne:
wskst->kod artykul.kod (*wskst).kod
*/