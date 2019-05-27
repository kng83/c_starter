/*najwazniejsza relacja wskaznik tablica

daty + 2 == &daty[2] // ten sam adres
*(daty + 2) == daty[2] // ta sama wartosc

//i jeszcze to (element tablicy bez numera to adres pierwszego elementu)
domek == &domek[0]

//i jeszcze suma czgos (od razu inkrementacja 
)
suma += *poczatek++;
suma += *paczatek; //wersja windocza
poczatek++;
//skonczyles na430
*/

//przyklad str 424
#include <stdio.h>
#define MIESIACE 12
int main(void)
{
    int dni[MIESIACE] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int index;
    for (index = 0; index < MIESIACE; index++)
        printf("Miesiac %d ma %d dni.\n", index + 1,
               *(dni + index)); // rownowazne dni[index]
         printf("Rozmiar tablicy tab wynosi %d bajtow.\n", sizeof dni);
    return 0;
}