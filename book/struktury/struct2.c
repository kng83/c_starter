#include <stdio.h>

struct zupa
{
    int kalorie;
    int ilosc;
    char nazwa[20];
};
int main()
{
    printf("start");
    struct zupa rosul = {
        10,
        20,
        "rosul"
    };

    struct zupa *dzis;
    dzis = &rosul; //tu dajemy adres zeby dobrac sie wskaznikiem
    printf("\nDzisiejsza zupa ma  %i kalorii", rosul.kalorie);
    printf("\nDzisiejsza zupa ma  %i kalorii", dzis->ilosc);
    printf("\nNazwa potrawy to %s",dzis->nazwa);
}
//motto
//dzis->kalorie == rosul.kalorie if dzis == &rosul