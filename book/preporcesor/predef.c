// predef.c -- identyfikatory predefiniowane
#include <stdio.h>
void czemu_ja();
int main()
{
    printf("Plik: %s.\n", __FILE__);
    printf("Data: %s.\n", __DATE__);
    printf("Czas: %s.\n", __TIME__);
    printf("Wersja: %ld.\n", __STDC_VERSION__);
    printf("Wiersz nr: %d.\n", __LINE__);
    printf("Nazwa funkcji: %s\n", __func__);
    czemu_ja();
    return 0;
}
void czemu_ja()
{
    printf("Nazwa funkcji: %s\n", __func__);
}

/*
#line 1000 // ustawia biezacy numer linii na 1000
#line 10 "cool.c" // ustawia biezacy numer linii na 10 oraz
// zmienia nazwe pliku na cool.c
*/

//error te makro wyswietli error
/*
#if __STDC_VERSION__ != 201112L
#error To nie C11
#endif
*/
