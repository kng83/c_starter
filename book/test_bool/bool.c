#include <stdbool.h>
#include <stdio.h>

//str 345
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
    bool w = zle_granice(4L,10L, 2L, 30L);
    printf("what is %u, %u , %u",w,false,true);
}