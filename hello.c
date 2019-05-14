#include <stdio.h>
#include <string.h>

#define  IMIE "Bobo"
int main(){

//test sizeof
char name[20]= "Pawles";
printf("\nsizeof my name %i",sizeof(name));

//test strlen
printf("\nsizeof my name %i",strlen(name));

//sprawdzam define
printf("\nPiotrek nic nie robi %s",IMIE);

}
 
