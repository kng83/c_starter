#include <stdio.h>
#include <ctype.h>

int guessANumber(int);
void testScanf();
//pobranie staylych z pliku stale
int main(){
    testScanf();

}

void testScanf(){
        unsigned width , length;
    int check1 ,check2,someValue;
    printf("podaj szerokosc\n:");
    check1 = scanf("%d",&width);

    printf("podaj dlugosc\n:");
    check2 = scanf("%d",&length);

    //dla 1 check jest ok
    printf("\nczy bled %d i %d",check1,check2);
    printf("\npole wynosi %d",width * length);

    printf("\npomin dwie pierwsze liczby:");
    scanf("%*d %*d %d",&someValue);
    printf("\nOtrzymana 3 liczba to %d",someValue);
}


