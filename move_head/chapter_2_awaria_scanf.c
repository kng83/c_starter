#include<stdio.h>

int main(){

char food[7];
puts("\nWpisz nazwe ulubionego jedzenia: ");
scanf("%s",food);
printf("\nTwoje jedzenie ulubione to %s",food);

char food2[8];
puts("\nWpisz nazwe ulubionego jedzenia 2: ");

fgets(food2,sizeof(food2),stdin);
printf("\nTWOJE jedzenie ulubione to %s",food2);



}