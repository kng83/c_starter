#include <stdio.h>
#include <ctype.h>
#define TRIM ' '
#define FALSE 4>6


int main(){
    char ch;
    ch = getchar();
        if(ch == '1') goto one;
        if(ch == '2') goto two;

printf("\nZla liczba");
return 0;

one:printf("is one"); 
return 0;
two:printf("is two");
return 0;
}