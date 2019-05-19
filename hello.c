#include <stdio.h>
#include <ctype.h>
#include <stdarg.h>

char hart[] = "Stop";
char *head = "star";
void main2(void);

void main2()
{
    int i;
    for (i = 0; i < 4; i++){
        putchar(hart[i]);
    }
    putchar('\n');

    for (i = 0; i < 4; i++){
        putchar(head[i]);
    }
    putchar('\n');
}

int main(){
    int i;
    //teraz wskaznik wskazuje na hart
    head = hart; //to jest mozliwe bo wskaznik odwrotnie nie
    for (i = 0; i < 4; i++){
        putchar(*(hart+i));
    }
    putchar('\n');

    for (i = 0; i < 4; i++){
        putchar(*(head+i));
    }
    putchar('\n');
    return 0;
}
