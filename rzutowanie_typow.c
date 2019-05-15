#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

#define count 4
int main(){
int a = 4;
float b = 10.0;
int c =0;
printf("\nto jest wynik %f",a + b);

//przyklad rzutowania typow
int myszy=0;
myszy = (int) b + a;
printf("\njest %i myszy",myszy); //14

//atoi w przypadku nie liczby zwraca 0;
char lancuch[5] = "12";
myszy = atoi(lancuch) + 4;
printf("\nSprawdzenie rzutowania char %i",myszy); //16

//sprawdzenie automatycznego rzutowania typow
printf("\nautomatyczne rzutowanie %i",c=b); //10

//dla floata to atof dla int to atoi (ascii to float or ascii to int);
printf("\nsprawdzenie atoi z floatem %f a some float to %f",atof("12.3"),4.33); //0.000 zero floatowe i nie dziala
}
