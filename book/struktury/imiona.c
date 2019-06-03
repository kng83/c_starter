// imiona3.c -- wskazniki i malloc()
#include <stdio.h>
#include <string.h> // potrzeba funkcji: strcpy(), strlen()
#include <stdlib.h> // potrzeba funkcji:malloc(), free()
#define DL 81
struct daneos
{
    char *imie; // uzycie wskaznikow
    char *nazwisko;
    int litery;
};
void pobierz(struct daneos *); // alokuje pamiec
void oblicz(struct daneos *);
void pokaz(const struct daneos *);
void wyczysc(struct daneos *); // zwalnia pamiec
char *wczytaj(char *z, int ile);
int main(void)
{
    struct daneos osoba;
    pobierz(&osoba);
    oblicz(&osoba);
    pokaz(&osoba);
    wyczysc(&osoba);
    return 0;
}
void pobierz(struct daneos *wsk)
{
    char temp[DL];
    printf("Podaj swoje imie.\n");
    wczytaj(temp, DL);

    // alokuje pamiec dla lancucha bylo char a dalem void i dziala
     wsk->imie = (void *)malloc(strlen(temp) + 1);

    // kopiuj lancuch do zaalokowanej pamieci
    strcpy(wsk->imie, temp);
    printf("Podaj swoje nazwisko.\n");
    wczytaj(temp, DL);

    //+1 dla znaku '/0'
    wsk->nazwisko = (char *)malloc(strlen(temp) + 1);
    strcpy(wsk->nazwisko, temp);
}
void oblicz(struct daneos *wsk){
    wsk->litery = strlen(wsk->imie) +
                  strlen(wsk->nazwisko);
}

void pokaz(const struct daneos *wsk){
    printf("%s %s, Twoje imie i nazwisko skladaja sie z %d liter.\n",
           wsk->imie, wsk->nazwisko, wsk->litery);
}
//zwolnienie pamieci od malloc
void wyczysc(struct daneos *wsk)
{
    free(wsk->imie);
    free(wsk->nazwisko);
}
char *wczytaj(char *z, int ile)
{
    char *wynik;
    char *newLine;
    wynik = fgets(z, ile, stdin);
    if (wynik)
    {
        newLine = strchr(z, '\n'); // szukamy nowego wiersza
        if (newLine)               // jesli adres jest rozny od NULL
            *newLine = '\0';       // zamieniamy znak nowego wiersza na pusty
        else
            while (getchar() != '\n')
                continue;
    }
    return wynik;
} 