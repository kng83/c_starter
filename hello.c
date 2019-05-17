#include <stdio.h>
#include <ctype.h>
#include <stdarg.h>



void main(void){
    int tab[]={10,202,34};
    int suma =0;
    for(int i = 0; i<(sizeof tab)/sizeof(int);i++){
        suma+=tab[i];
    }
    printf("oto suma %i",suma);
    printf("\nadres tablicy to %x",tab);
}

