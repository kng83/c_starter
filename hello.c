#include <stdio.h>
#include <ctype.h>
#include <stdarg.h>


int main(void){
    int z[4][2] = {{4,22},{2,11},{5,33},{5}};

    printf("z %p , z[0] = %p\n", z, z[0]);
    printf("&z[0][0] = %p &z = %p\n",&z[0][0], *z);
    printf("**z = %i\n",**z); //podwojna dereferencja bedzie odczytywala wartosc tablicy 4
    printf("**(z +1) = %i na nastepna wartosc\n" ,**(z+1)); //odczytuje z[0][1];
    printf("z[1][0] = %i\n",*(*z+1)); //22
    printf("z[1][0] = %i\n",*(z+1)); //22
    printf("z[1][0]+1 = %i\n",**z+1); //5 (bo dereferencja ma wyzszy piorytet)

    
}
