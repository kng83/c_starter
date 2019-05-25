#include<stdio.h>
#include<stdlib.h>
#include <ctype.h>
#include "model.h"
#include "add_question.h"
#include "game.h"
#include "banners.h"

//**Declarations 
void start();
void menuInput();
void beginGame();
extern void starBanner(void);


int main(){
    start();
}

void start(){
    startBanner();
    printf("[1] rozpocznij gre\n");
    printf("[2] dodaj pytanie\n");
    printf("[3] wcisnij kazdy inny aby zakonczyc\n");
    menuInput();
}

 void menuInput(){
    char choosenValue[1];
    int choosenNumber;
    
    gets(choosenValue);
    choosenNumber = atoi(choosenValue);

   if(!choosenNumber){
       printf("Bledny kod zakonczyles rozgrywke");
       exit(1);
   } 

   if(choosenNumber == 1) beginGame();
   if(choosenNumber == 2 ) addQuestion();

   printf("\nZakonczyles rozgrywke");
   exit(0);

}

