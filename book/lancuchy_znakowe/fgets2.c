#include <stdio.h>
#include<string.h>

char *wczytaj(char *z, int ile)
{
    char *wynik;
    int i = 0;
    wynik = fgets(z, ile, stdin);
    if (wynik) // wynik rozny od NULL
    {
        while (z[i] != '\n' && z[i] != '\0')
            i++;
        if (z[i] == '\n')
            z[i] = '\0'; // znak nowego wiersza -> znak pusty
        else             // z[i] == '\0'
            while (getchar() != '\n')
                continue;
    }
    return wynik;
}

int main()
{
    char tab[12];
    char tab2[12];
   // *tab2 = wczytaj((char[5]){'a','b','c'},5);
    strcpy(tab2,"kot 3");

    printf("0 sprawdz adres wczytaj %p",&wczytaj);
    printf("1 %s",wczytaj(tab,10));
    printf("2 %s",wczytaj(tab,10));
    printf("\n4 tablica %s i ostatni znak %c",tab2,tab2[11]);
}