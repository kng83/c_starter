 /* file minunit_example.c */
 
 #include <stdio.h>
 #include "minunit.h"
 
  int tests_run = 0;
 
 int foo = 7;
 int bar = 5;
 
describe('kot'){
     mu_assert("error, foo != 7", foo == 7);
     return 0;
 }

void func(int nb, void (*f)(int)) {
    int i;
    for (i = 0; i < nb; i++) f(i);
}

 static char * test_bar() {
     mu_assert("error, bar != 5", bar == 5);
     return 0;
 }
 
 static char * all_tests() {
     mu_run_test(test_foo);
     mu_run_test(test_bar);
     return 0;
 }
 
 int main(int argc, char **argv) {
     
       func(4, LAMBDA(void _(int v) {
        printf("%d\n", v);
    }));

     char *result = all_tests();
     if (result != 0) {
         printf("%s\n", result);
     }
     else {
         printf("ALL TESTS PASSED\n");
     }
     printf("Tests run: %d\n", tests_run);
 
     return result != 0;
 }