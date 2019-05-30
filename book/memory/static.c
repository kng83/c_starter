/* lok_stat.c -- uzywanie statycznych zmiennych lokalnych */
#include <stdio.h>
void sprawdz_stat(void);
int main(void)
{
    int licznik;
    for (licznik = 1; licznik <= 3; licznik++)
    {
        printf("Iteracja nr: %d:\n", licznik);
        sprawdz_stat();
    }
    return 0;
}
//tu jest zmienna statyczna o lacznosci wew. jest ona to inkrementowana 3 krotnie.
void sprawdz_stat(void)
{
    int znikam = 1;
    static int trwam = 1; //trawam ma pamiec
    printf("znikam = %d, a trwam = %d\n", znikam++, trwam++);
}