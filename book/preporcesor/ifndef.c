//dzieki temu dokladamy jesli nie bylo dolozone
#ifndef DANEOS_H_
#define DANEOS_H_
// stale
#define DL_LAN 32
// deklaracje struktur
struct daneos_st
{
    char imie[DL_LAN];
    char nazw[DL_LAN];
};
// typedef
typedef struct daneos_st daneos;
// prototypy funkcji
void wprowadz(daneos *);
void wyswietl(const daneos *);
char *wczytaj(char *z, int ile);
#endif

//tu program
#include <stdio.h>
//#include "daneos.h"
//#include "daneos.h" /* przypadkowe drugie dolaczenie */
int main()
{
    daneos zwyciezca = {"Less", "Ismoor"};
    printf("Zwyciezca jest %s %s.\n", zwyciezca.imie,
           zwyciezca.nazw);
    return 0;
}