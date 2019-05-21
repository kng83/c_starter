#include <stdio.h>
#include <ctype.h>
#include <time.h>
#include <stdlib.h>

//**Constanst
#define MAX_LEVEL 10

//**Declarations
void initializeRandom();
void playGame();
void findQuestion(int level);

//**Main
void beginGame(){
    printf("\nGra sie rozpoczela");
    initializeRandom();
    playGame();
}

void playGame(){
    int level;
    for(level =1 ; level <MAX_LEVEL; level++ ){
        findQuestion(level);
    }

   
}

//** finding question to specific level
void findQuestion(int level){
    
    //first find every qeuestion with level
    //load to question[]
    //take random question from question[]
    //random answers from the question element
    //print the question
    //return to make next question
    //or get back to main menu
    
    int r = rand() % 3;
    printf("\npytanie %i %i",level ,r);
}

void initializeRandom(){
     srand(time(NULL));   // Initialization, should only be called once.
}