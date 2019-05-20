#include <stdio.h>
#include <ctype.h>
#include <unistd.h>
#include <stdlib.h>


#define MAX_STRING 81
#define DEF_STRING "Jestem z#definiowanym lancuche"

void with_puts(void);
void with_fputs(void);
void with_printf(void);
void showChar(const char *);


int main(){
    with_puts();
    with_fputs();
    with_printf();

    showChar("kot idzie tam");
}

void with_puts(){
    char some_txt[80] = "written to table";
    char other_txt[80] = "to help pointer";
    char * some_txt2 = other_txt;
    
    puts("Some text");
    puts(DEF_STRING);

    puts(some_txt);
    puts(some_txt2);

    puts(&some_txt[4]); //tu musimy dac adres zeby wskaznik uzyskac
    puts(some_txt2 +4);
}

void with_fputs(){
    char row[81]="kot idzie spac\n";
    fputs(row,stdout);
}

void with_printf(){
    printf("\n------------------------------------\n");
    char tab[] = "soket";  
    printf("to jest aoti %x",(char)('\0'));
    printf("\n------------------------------------\n"); 
}

void showChar(const char * chain){
  //  while(*chain !='\0') // to jest to samo
    while(*chain)
        putchar(*chain++);
}