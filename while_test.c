#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

#define count 4

void while_test(void);
void while_break(void);
void test_operator(void);
void while_short(void);


int main(){
while_test();
while_break();
test_operator();
while_short();

    /* code */
}

void while_test(){
  int local_count = count;
  while(local_count){
      printf("\n oto local_count %i",local_count--);
  }
}

void while_break(){
    int local_count = count;
    while(1){
        printf("\n wyjscie dla local_count = 2 local_count = %i",local_count);
        local_count--;
        if(local_count <=2) break;
    } 
}
//odejmowanie petli zawarte w while
void while_short(){
  int local_count = count;
  while(local_count--) printf("\n oto short_local_count %i",local_count);
  
}

//test operatora dziwny
void test_operator(){
    int some=0, dom=3 ,come=1;
    some = come  = dom + come;
    printf("\n some=%i ,dom=%i, come=%i",some,dom,come);
}