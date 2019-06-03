#include<stdio.h>

//void pokaz(void (* fw)(char *), char * lan);
void map( int(*pfn)(int) ,int tab[],int size);
int add4(int val);

int main(){
 int tab[10] = {0,1,2,3,4,5,6,7,8,9};
 map(add4,tab,sizeof(tab)/sizeof(int));

 puts("Wyswietl elementy po modyfikacji");
 for(int i=0;i<sizeof(tab)/sizeof(int); i++){
     printf("%i ",tab[i]);
 }

}
//Przyklad jak zrobic map w c
void map( int(*pfn)(int) ,int tab[],int size){
    for (int i = 0; i<size ; i++){
        tab[i] = pfn(tab[i]);
    }
}

int add4(int val){
    return val + 4;
}

