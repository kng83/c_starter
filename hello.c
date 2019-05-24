#include <stddef.h>
#include <stdio.h>
#define swap(type, foo, bar) ({type tmp; tmp=foo; foo=bar; bar=tmp;})

//*** THIS file isn't add yet.

void check_offset();

typedef struct ADDR {
  char name[50];
  char street[50];
  int phone;
}ADDR;
   
int main () {

    int a = 4;
    int b = 5;
    swap(int,a,b);
    printf("%i i %i",a,b);

   printf("names offset = %d byte in address structure.\n",
   offsetof(ADDR, name));

   printf("street offset = %d byte in address structure.\n",
   offsetof(ADDR, street));

   printf("phone offset = %d byte in address structure.\n",
   offsetof(ADDR, phone));

   return(0);
}

void check_offset(){
    
}