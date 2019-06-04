#include <stdio.h>
//inline funkcje maja byc najszybsze
inline static void pobierz_linie() // definicja/prototyp funkcji inline
{
    while (getchar() != '\n')
        continue;
}
int main()
{
   pobierz_linie(); // wywolanie funkcji
}
//765