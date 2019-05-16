#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

#define FALSE 0
#define TRUE 1

void check_input(long num);
int main(){

while(TRUE){ printf("some is tekst"); break;};

check_input(10);

}

void check_input(long num){
    while(scanf("%ld",&num)==1){
        printf("Podaj liczbe:");
    }
}
