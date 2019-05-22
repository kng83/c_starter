#include <stdio.h>
#include <ctype.h>
#include <time.h>
#include <stdlib.h>

//**Constanst
#define MAX_LEVEL 10
#define MAX_QUESTION_ARR 20

//**Declarations
void initializeRandom();
void playGame();
void findQuestion(int level);
DataModel  readLineByQuestionLevel(int level);
void findQuestionByLevel(FILE *fp, DataModel *questionsByLevel, int level);

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
    
    //first find every question with level
    //load to question[]
    //take random question from question[]
    //random answers from the question element
    //print the question
    //return to make next question
    //or get back to main menu
    
    int r = rand() % 3;
    printf("\npytanie %i %i",level ,r);
}

DataModel  readLineByQuestionLevel(int level){
    static DataModel question; //returned question
    DataModel questions[MAX_QUESTION_ARR]; //array which be filled with question
    FILE *fp; //file pointer

    printf("\n[1]******* Rozpoczynamy gre ***************************************");
    //**Check data file;

    if ((fp = fopen("data.csv", "a+")) == NULL){
        fprintf(stdin, "Nie moge otworzyc pliku \" words \".\n");
        badRoute();
    }

    return question;
}

void findQuestionByLevel(FILE *fp, DataModel * questionsByLevel,int level){
    char ch;
    long counter, end_position, new_line_position, first_semicolon_in_line;
    fseek(fp, 0L, SEEK_SET);  //na poczatek pliku


     for (counter = 1; counter <= end_position; counter++){
        //**Find last semicolon and of line
        fseek(fp, -counter, SEEK_END);
        ch = getc(fp);
        if( ch== ';'){
            first_semicolon_in_line = end_position - counter;
        }
        if (ch == '\n'){
            new_line_position = end_position - counter;
            break;
        }
    }
}

void initializeRandom(){
     srand(time(NULL));   // Initialization, should only be called once.
}