#include <stdio.h>
#include <ctype.h>
#include <stdarg.h>


long add(const int tab[],int n);
void main(void){
    const int tab[]={10,202,34};
    int s =add(tab,(sizeof tab)/sizeof(int));
    printf("oto suma %i",s);
    printf("\nadres tablicy to %x",tab);
}

long add(const int tab[],int n){
    int suma =0;
    for(int i = 0; i<n;i++){
        suma+=tab[i];
    }
    return suma;
}
