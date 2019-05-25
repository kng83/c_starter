#include<stdio.h>
#define SCREEN_HEIGHT 25

void startBanner(void){
    printf("\n");
    printf("\n***************************************************");
    printf("\n************** Start gry milionerzy ***************");
    printf("\n***************************************************");
    printf("\n");
}

void clearScreen(void){
  int i;  
  for ( i = 0; i < SCREEN_HEIGHT; i++ )
    putchar ( '\n' );

}