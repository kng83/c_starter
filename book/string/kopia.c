/* kopia2.c -- demo strcpy() */
/* str 509 to lista funkcji do string  !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!*/
#include <stdio.h>
#include <string.h> /* deklaruje strcpy() */
#define SLOWO "cukier"
#define ROZMIAR 40
int main(void)
{
    const char *zrodlo = SLOWO;
    char kopia[ROZMIAR] = "Podaj mnie do sadu.";
    char *wl;
    puts(zrodlo);
    puts(kopia);

    // lepszy jest  strncpy(cel, zrodlo, n) bo n to ilosc znakow
    // kopia + 6 bierze 6 znakow z kopi
    wl = strcpy(kopia + 6, zrodlo);
    puts(kopia); //Podaj cukier
    puts(wl); //cukier (tu jest zwracane zrodlo)
    return 0;
}
/*
cukier
Podaj mnie do sadu.
Podaj cukier
cukier
*/
//rozwiazanie dla strncpy aby dodac znak '\0'
//strncpy(vslowa[i], temp, ROZMIAR_CELU - 1);
//vslowa[i][ROZMIAR_CELU - 1] = '\0';f

