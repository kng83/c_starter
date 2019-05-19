#include <stdio.h>
#include <ctype.h>
#include <stdarg.h>

char *t1 = "cos tam jest napisane";
char tw[] = "jakis tekst";
char *t2 = "www sss kkk ";
char *t3[3] = {"pierwszy","dwa","trzzy"};


int main(){
    //-tu odejmienmy 1 by nie bylo znaku '\0'
    for(int i=0;i<sizeof(t1)/sizeof(char)-1;i++){
        putchar(t1[i]);
    }
    printf("\njakis");
    puts("\nsome tekst ohter");
    puts(t3[0]);
    printf("check");
    char imie[10];
    printf("\npodaj imie \n");
 //   gets(imie);
  //  puts(imie);
    puts(tw);
  //  puts(*(t3[1]));
}
