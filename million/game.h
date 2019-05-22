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
void mapperArray(FILE * fp, long arr[][6]);

//**Main
void beginGame(){
    printf("\nGra sie rozpoczela");
    initializeRandom();
    playGame();
}

void playGame(){
    int level;
    printf("\n[1]******* Rozpoczynamy gre ***************************************");
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
    
 //   int r = rand() % 3;
  //  printf("\npytanie %i %i",level ,r);

     readLineByQuestionLevel(level);
}

DataModel  readLineByQuestionLevel(int level){
    static DataModel question; //returned question
    DataModel questions[MAX_QUESTION_ARR]; //array which be filled with question
    FILE *fp; //file pointer

    //**Check data file;
    if ((fp = fopen("data.csv", "r")) == NULL){
        fprintf(stdin, "Nie moge otworzyc pliku \" words \".\n");
        badRoute();
    }
    findQuestionByLevel(fp,questions,level);

    fclose(fp);

    return question;
}

void findQuestionByLevel(FILE *fp, DataModel * questionsByLevel,int level){
    char ch;
    char content[ANSWER];
    int shortCounter,colonCounter;
    int questionsIndex =0;
    long counter, end_position, new_line_position, first_semicolon_in_line;
    
    fseek(fp,0L,SEEK_END);//idz na koniec pliku
    end_position = ftell(fp); //pozycja na koncu
    fseek(fp, 0L, SEEK_SET);  //na poczatek pliku

    counter =0 ;
    shortCounter = 0;
     for (counter; counter <= end_position; counter++){
        //**Find last semicolon and of line
        fseek(fp, counter,0L);
        ch = getc(fp);
        if(ch!=';' || ch!='\n'){
            content[shortCounter] = ch;
            shortCounter ++;
        }
        if(ch==';'){
            shortCounter=0; //aby poczatek by w zerze
        }
    
        printf("%c",ch);
        }
    }

void initializeRandom(){
     srand(time(NULL));   // Initialization, should only be called once.
}

void mapperArray(FILE * fp, long arr[][6]){
    //***Array element look like this 
    //[level][correct_answer_position][fake_answer_pos][fake_2][fake_3][end_position]
    //1;1;g;b;b;b;
    //***
    char ch;
    char content[ANSWER];
    int shortCounter,colonCounter,newLineCounter;
    int questionsIndex =0;
    long counter, end_position, new_line_position, first_semicolon_in_line;
    
    fseek(fp,0L,SEEK_END);//idz na koniec pliku
    end_position = ftell(fp); //pozycja na koncu
    fseek(fp, 0L, SEEK_SET);  //na poczatek pliku

    counter =0 ;
    shortCounter = 0;
    colonCounter = 0;
    newLineCounter =0;

     for (counter; counter <= end_position; counter++){
        //**Find last semicolon and of line
        fseek(fp, counter,0L);
        ch = getc(fp);
        if(ch!=';' || ch!='\n'){
            content[shortCounter] = ch;
            shortCounter ++;
        }
        if(ch==';'){
            colonCounter++;
            shortCounter=0; //aby poczatek by w zerze
        }
        if(colonCounter==1){
            arr[new_line_position][0L]= atol(content);

        }
        //aby wylapac pozycje wszystkie
        if(colonCounter >1){
            arr[new_line_position][colonCounter] = counter;
        }

        if(ch=='\n'){
            shortCounter=0;
            colonCounter=0;
            new_line_position++;
        }
  
        printf("%c",ch);
        
    }

}