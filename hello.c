#include <stdio.h>

int guessANumber(int);
void testScanf();
//pobranie staylych z pliku stale
int main(){
   // testScanf();
    guessANumber(432);

}

int guessANumber(int pattern){
     int someValue=0;
     int check =0;
     printf("\nzgadnij liczbe:");
     check = scanf("%d",&someValue);

     if(check !=1 || check!=NULL){
         someValue =0;
         check = 0;
         printf("\nvalue of someValue %s and patter %x",someValue,pattern);
         return guessANumber(pattern);
     }else{

     }

    if(someValue == pattern){
        printf("\nZgadles to liczba %d Hz",someValue);
        return 1;
    }else{        
         return guessANumber(pattern);
    }
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


