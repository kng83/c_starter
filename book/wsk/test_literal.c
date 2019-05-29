#include <stdio.h>

int main(){
(int [2]){10,20}; //literal
int *p_int;
p_int = (int[2]){1,2};
printf("to jest cos %i",*(p_int+1));

//dzieki temu mozna zrobic jakis wskaznik do tablicy i nie dawac tablicy nazwy
int *p_int2 =  (int[2]){1,2};
printf("\nto jest kot %i",*(p_int2));
}

//int (*wsk2)[4]; // deklaracja wskaznika do tablicy
//int wsk2[][4]; // to samo co wyzej