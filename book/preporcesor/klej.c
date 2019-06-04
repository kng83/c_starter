// klej.c -- uzycie opertora ##
#include <stdio.h>
#define XNAZWA(n) x##n
#define WYPISZ_XN(n) printf("x" #n " = %d\n", x##n);
int main(void)
{
    // teraz mam zmienna x1 i x2
    int XNAZWA(1) = 14; // rozwijane do int x1 = 14;
    int XNAZWA(2) = 20; // rozwijane do int x2 = 20;
    int x3 = 30;
    printf("Zmienna x1=%i\n",x1);
    WYPISZ_XN(1); // rozwijane do printf("x1 = %d\n", x1);
    WYPISZ_XN(2); // rozwijane do printf("x2 = %d\n", x2);
    WYPISZ_XN(3); // rozwijane do printf("x3 = %d\n", x3);
    return 0;
}