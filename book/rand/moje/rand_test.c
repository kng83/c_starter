/* r_test0.c -- sprawdza funkcje rand0() */
/* nalezy kompilowac z plikiem rand0.c */
// gcc -g -o rand rand0.c rand_test.c
#include <stdio.h>
extern int rand0(void);  // extern nie jest konieczne
extern void srand0(unsigned int x);
int main(void) {
    int liczba;
    unsigned ziarno;
    printf("Podaj wartosc ziarna:\n");
    while (scanf("%u", &ziarno) == 1) {
        srand0(ziarno); /* reset ziarna */
        for (liczba = 0; liczba < 5; liczba++) printf("%hd\n", rand0());
        printf("Podaj nastepna wartosc ziarna (k to koniec):\n");
    }
    printf("Koniec\n");
    return 0;
}