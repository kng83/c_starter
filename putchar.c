#include <stdio.h>
#include <ctype.h>
#define TRIM ' '


int main(){
    char ch='Z';
    //idiom znakowy uzwaz bo  != ma wyzszy piorytet
    while((ch = getchar())!='\n'){
        if(isalpha(ch)){
            putchar(ch+1);
        }else{

            putchar(ch);
             }
    }
    putchar(ch);
    return 0;
}