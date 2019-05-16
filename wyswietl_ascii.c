#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>


int main(){
    char ch;
    for(ch ='a';ch <='z';ch++){
        printf("\nWartosc ascii dla znaku %c wynosi %x",ch,ch);
    }
}