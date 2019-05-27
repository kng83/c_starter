// oznaczon.c -- uzycie oznaczonej inicjalizacji
#include <stdio.h>
#define MIESIACE 12
int main(void)
{   //
    //same zera i 6 element 31 u mnie not supported (g++ dziala w gcc);
    //29 jest nadpisywane przez [0]=1
    int dni[MIESIACE] = {29,[6] = 31,[0]=1};
    int i;
    for (i = 0; i < MIESIACE; i++)
        printf("%2d %d\n", i + 1, dni[i]);
    return 0;
}