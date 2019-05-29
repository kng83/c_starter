/* wysw1.c -- wyswietla lancuch bez dodawania \n */
#include <stdio.h>

//str 489
void wysw1(const char * lancuch) /* lancuch nie ulega zmianie */
{
 while (*lancuch != '\0')
 putchar(*lancuch++);
}

int main(){
 char lan[20] = {'k','o','t','\0'};
 wysw1(lan);   
}
