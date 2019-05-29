/* fgets1.c -- stosowanie fgets() i fputs() */

// zaleca sie fgets bo ma rozmiar tablic samo gets() jest niebezpieczne bo mozna buffor przepelnic
#include <stdio.h>
#define DLUGOSC 14
int main(void)
{
 char slowa[DLUGOSC];
 puts("Prosze wprowadzic lancuch.");
 fgets(slowa, DLUGOSC, stdin);
 printf("Wprowadzony lancuch (dwa razy: z puts() i fputs()):\n");
 puts(slowa);
 fputs(slowa, stdout); //nie dodaje znaku nowej lini
 puts("Prosze wprowadzic kolejny lancuch.");//dodaje znak nowej lini
 fgets(slowa, DLUGOSC, stdin);
 printf("Wprowadzony lancuch (dwa razy: z puts() i fputs()):\n");
 puts(slowa);
 fputs(slowa, stdout);
 puts("Gotowe.");
 return 0;
}