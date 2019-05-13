#include <stdio.h>

typedef struct t_hello {
    int (*someFunction)(int arg1);
    int (*someOther)(int arg1);
} t_hello;

// Functions declaration
int foo(int);
t_hello constructhello(void);


int main(void)
{
    t_hello aHello = constructhello();
    printf("Print hello: %d\n", aHello.someFunction(10));
    printf("Print hello: %d\n", aHello.someOther(105));

    return 0;
}

int foo(int arg1){
    return arg1;
}

t_hello constructhello(void){
    t_hello aHello;
    aHello.someFunction = &foo;
    aHello.someOther = &foo;
    return aHello;
}