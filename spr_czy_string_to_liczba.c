#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

int guessANumber(int);
int digits_only(const char *s);
int main(){
    guessANumber(432);

}

int guessANumber(int pattern){
     char someValue[10];
     printf("\nzgadnij liczbe:");
     scanf("%s",someValue);

    //sprawdzenie czy w stringu jest liczba
     if(!digits_only(someValue)){
         printf("\nto nie jest liczba");
         return guessANumber(pattern);
     }
    
    //convert string to number
    int convertedToInt = atoi(someValue);


    if(convertedToInt == pattern){
        printf("\nZgadles to liczba %d Hz",convertedToInt);
        return 1;
    }else{        
        printf("\nto nie ta liczba");
        return guessANumber(pattern);
    }
}

// zwraca 1 gdy wszystko ok
int digits_only(const char *s){
    while (*s) {
        if (isdigit(*s++) == 0) return 0;
    }

    return 1;
}

