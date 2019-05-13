#include <stdio.h>

int main(){
    char kot[10] = "Tsaaw\a\n";
    printf("to jest %s\n",kot);
    printf("to jest %d\n",sizeof(kot));
    printf("to jest wysow \f i co sie stalo");
    printf("to jest %d",sizeof(kot));
    unsigned short int kon =4;
    printf("\nto jes dlugosc kon %i",sizeof(kon));
    char alpha = 'A';
    printf("\n size of alpha %i",sizeof(alpha));

}
 