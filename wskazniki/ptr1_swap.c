#include <stdio.h>
#include <ctype.h>
#include <stdarg.h>
#include<string.h>

void swap(int *u, int *v);
void swap2(int *u, int *v);

int main(){
    int one=5;
    int two=4;
    swap(&one,&two);
    printf("\npo zamienie one %i i two %i",one, two);
    swap2(&one,&two);
    printf("\npo zamienie one %i i two %i",one, two);
}
//jak zapominisz str 295
void swap(int *u, int *v){
    int temp;
    temp = *u;
    *u=*v;
    *v=temp;
}

void swap2(int *u, int *v){
 int temp;
    temp = *u;
    *u=*v;
    *v=temp;
     printf("\n*u wskazuje na pamiec %p i a w komurce jest %i",u,*u);
    
}
