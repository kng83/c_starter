#include <stdio.h>
#include <stdlib.h>
#define log_info(M, ...) fprintf(stdout, "[INFO] (%s:%d) " M "\n", __FILE__, __LINE__, ##__VA_ARGS__)
#define Callback 
// Macro to get a random integer with a specified range
#define getrandom(min, max) \
    ((rand()%(int)(((max) + 1)-(min)))+ (min))

void callback(void){
    printf("\nthis is callback");
}

void fnWithCallback(char *message, void (callback)(void)){
    callback();
}

int main()
{
   printf("test ok");
  
   int var = 10;
   fprintf(stdout,"\nthis (%s:%d) \n","kot","pies","lodka");
   log_info("my variable is %d", var);
   fnWithCallback("some",callback);
   printf("\nget random %i",getrandom(1,10));

}