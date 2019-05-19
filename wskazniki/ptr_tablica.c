#include <stdio.h>
#include <ctype.h>
#include <stdarg.h>

void some_fn(const double tab[],int);
int main(){
const double  tab[10] ={33,32,37,18,19,23,14,1,33,3};
some_fn(tab,sizeof tab/sizeof(double));

}

void some_fn(const double tab[],int n){
int i;  
for( i=0;i<n;i++){
    printf("%10.2f",tab[i]);
    if(i % 5==0){
        putchar('\n');
    }
}
if(i % 6 !=0){
    putchar('\n');
}
}