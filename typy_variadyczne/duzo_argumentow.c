#include <stdio.h>
#include <ctype.h>
#include <stdarg.h>


void printargs(int arg1, ...){
  va_list ap;

  va_start(ap, arg1); 
  for (int i = arg1; i >= 0; i = va_arg(ap, int))
  printf("%d ", i);
  va_end(ap);
  putchar('\n');
}


int main(){
    printargs(1,2,3,4,-1);
    return 0;
}
