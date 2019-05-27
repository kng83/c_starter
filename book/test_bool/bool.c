#include <stdbool.h>
#include <stdio.h>


bool zle_granice(long poczatek, long koniec, long dolna, long gorna)
{
    bool zle = false;
    if (poczatek > koniec)
    {
        printf("%ld nie jest mniejsze od %ld.\n", poczatek, koniec);
        zle = true;
    }
    if (poczatek < dolna || koniec < dolna)
    {
        printf("Wartosci musza miec wartosc co najmniej: %ld.\n",
               dolna);
        zle = true;
    }
    if (poczatek > gorna || koniec > gorna)
    {
        printf("Wartosci musza miec wartosc co najwyzej: %ld.\n",
               gorna);
        zle = true;
    }
    return zle;
}

int main(){
    zle_granice(4L,10L, 2L, 3L);
}