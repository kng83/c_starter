/* astro.c -- wykorzystuje strncmp() */
#include <stdio.h>
#include <string.h>
#define ROZMIARLISTY 5
int main()
{
    //mozna zapakowac zdanie do tablicy i zrobic szukanie
    const char *lista[ROZMIARLISTY] = {
        "astronomia", "asteroida",
        "astrofizyka", "ostroga",
        "asteryzm"};
    int licznik = 0;
    int i;
    for (i = 0; i < ROZMIARLISTY; i++)
        if (strncmp(lista[i], "astro", 5) == 0)
        {
            printf("Znaleziono: %s\n", lista[i]);
            licznik++;
        }
    printf("Lista zawiera %d slowa zaczynajace sie"
           " na astro.\n",
           licznik);
    return 0;
}