#include<stdio.h>
#define SCREEN_HEIGHT 25

void startBanner(void){
    printf("\n");
    printf("\n***************************************************");
    printf("\n************** Start gry milionerzy ***************");
    printf("\n***************************************************");
    printf("\n\n");
    confirmSound();
}

void playGameBanner(void){
    printf("\n***************************************************");
    printf("\n**************** Rozpoczynamy gre *****************");
    printf("\n***************************************************");
    printf("\n\n");
    confirmSound();
}

void winnerBanner(void){
    printf("\n");
    printf("\n***************************************************");
    printf("\n************** Wygrales MILION ZLOTYCH !!!*********");
    printf("\n************** Wygrales MILION ZLOTYCH !!!*********");
    printf("\n************** Wygrales MILION ZLOTYCH !!!*********");
    printf("\n************** Wygrales MILION ZLOTYCH !!!*********");
    printf("\n************** Wygrales MILION ZLOTYCH !!!*********");
    printf("\n***************************************************");  
    printf("\n");
}
void playWinnerSound(void){
  printf("\a\a\a\a\a\a\a\a\a\a\a\a\a\a\a\a\a\a\a\a\a\a\a\a\a\a\a\a\a");
}

void confirmSound(void){
  printf("\a");
}

void clearScreen(void){
  int i;  
  for ( i = 0; i < SCREEN_HEIGHT; i++ )
    putchar ( '\n' );

}
void pressKeyToContinue(void){
  printf("\n******************************************************");
  printf("\n\t Wcisnij przycisk by kontynuowac");
  getchar();
}

//Jednak w millionerach jest 12 pytan
void playForCashBanner(int level){
 long payload[]={0,500,1000,2000,5000,10000,20000,40000,75000,125000,250000,500000,1000000};
 printf("\n***************************************************");
 printf("\n\t$$$ Grasz teraz o %d zlotych $$$",payload[level]);
 printf("\n***************************************************");
}

void questionLevelToBigBanner(void){
  printf("\nPytanie powinno miescic sie w przedziale od 0 do %i",MAX_LEVEL);
}