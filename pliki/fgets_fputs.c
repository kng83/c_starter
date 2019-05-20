#include <stdio.h>
#include <stdlib.h>
#define MAX 40
//dodajemy argumenty 
//mozna zrobic program z argumentami
//str 399;
//bierzemy wejscie z klawiatur i wrzucamy to na ekran
//nowa linia konczy cyrk
int main(){
 char row[MAX];
 while(fgets(row,MAX,stdin)!=NULL && row[0] !='\n')
  fputs(row,stdout);
  return 0;
}
