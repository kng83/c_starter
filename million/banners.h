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