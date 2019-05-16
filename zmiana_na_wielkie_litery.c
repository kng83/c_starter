#include <stdio.h>
#include <ctype.h>
#define TRIM ' '
#define FALSE 4>6


int main(){
    char ch='Z';
    //idiom znakowy uzwaz bo  != ma wyzszy piorytet
    while((ch = getchar())!='\n'){
        if(isalpha(ch)){
            //na wielkie
            putchar(ch=toupper(ch));
        }else{

            putchar(ch);
             }
    }
    putchar(ch);
    printf("\n %i",FALSE);
    return 0;
}