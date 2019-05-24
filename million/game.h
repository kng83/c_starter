#include <stdio.h>
#include <ctype.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>

//**Constans
#define MAX_LEVEL 10
#define MAX_QUESTION_ARR 20
#define MAX_QUESTION_LIST 300
#define SEMI_NUMBER 6

//**Declarations
void initializeRandom();
void playGame();
void findQuestion(int level);
DataModel readLineByQuestionLevel(int level);
int mapperArray(FILE *fp, long arr[][8]);
void testArr(long arr[][8]);
int questionsPerLevelArr(long levelArr[][8],long fullArr[][8],int fullArrlength,int level);
int randomOf(int);

//**Main
void beginGame()
{
    printf("\nGra sie rozpoczela");
    initializeRandom();
    playGame();
}

void playGame()
{
    printf("\n[1]******* Rozpoczynamy gre ***************************************");

    FILE *fp; //file pointer
    //**Check data file;
    if ((fp = fopen("data.csv", "r")) == NULL){
        fprintf(stdin, "Nie moge otworzyc pliku \" words \".\n");
        badRoute();
    }
    long mappedArr[MAX_QUESTION_LIST][8];
    long levelArr[MAX_QUESTION_LIST][8];
    int questionLines= mapperArray(fp, mappedArr);
    int level=1;
    int questionPerLevel = questionsPerLevelArr(levelArr,mappedArr,questionLines,level);
    printf("\nThere is %i questions",questionLines);
    printf("\nThere is %i questions on level %i",questionPerLevel,level);
    testArr(levelArr);
    printf("random number is %i",randomOf(questionPerLevel));


    // for (level = 1; level < MAX_LEVEL; level++){
    //     ;
    // }
    
}

//** finding question to specific level
void findQuestion(int level)
{

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

DataModel readLineByQuestionLevel(int level){
    static DataModel question;             //returned question
    DataModel questions[MAX_QUESTION_ARR]; //array which be filled with question
    FILE *fp;                              //file pointer

    //**Check data file;
    if ((fp = fopen("data.csv", "r")) == NULL){
        fprintf(stdin, "Nie moge otworzyc pliku \" words \".\n");
        badRoute();
    }
    fclose(fp);

    return question;
}

void initializeRandom(){
    srand(time(NULL)); // Initialization, should only be called once.
}

int mapperArray(FILE *fp, long arr[][8])
{
    /*** 
    * Array element look like this:
    * [index][level][start_text][correct_answer_position][fake_answer_pos][fake_2][fake_3][end_position]
    */
    char ch;
    char content[100];
    int shortCounter, colonCounter, newLineCounter;
    int questionsIndex = 0;
    long counter, end_position;

    fseek(fp, 0L, SEEK_END);  //idz na koniec pliku
    end_position = ftell(fp); //pozycja na koncu
    fseek(fp, 0L, SEEK_SET);  //na poczatek pliku

    counter = 0;
    shortCounter = 0;
    colonCounter = 0;
    newLineCounter = 0;

    for (counter; counter <= end_position; counter++){
        //**Find last semicolon and of line
        fseek(fp, counter, 0L);
        ch = getc(fp);

        if (ch != ';' || ch != '\n'){
            content[shortCounter] = ch;
            shortCounter++;
        }
        if (ch == ';'){
            colonCounter++;
            shortCounter = 0; //aby poczatek by w zerze

            //index
            if (colonCounter == 1){
                arr[newLineCounter][0] = atol(content);
            }
            //pick up level
            if (colonCounter == 2){
                arr[newLineCounter][1] = atol(content); //aby dac poziom pytania
                arr[newLineCounter][2] = counter+2; //aby wychwycici poczatek pytan
            }
            //catch up all positions
            if (colonCounter > 2){
                arr[newLineCounter][colonCounter] = counter + 1;
            }
        }
        if (ch == '\n'){
            counter++; //resolve double '\n\n'
            shortCounter = 0;
            colonCounter = 0;
            newLineCounter++;
        }
        //printf("end %lu newline %lu",counter,newLineCounter);
    }
    rewind(fp);
    return newLineCounter;
}

//Pass array contains elements with choosen level. Return number of elements for random usage.
int questionsPerLevelArr(long levelArr[][8],long fullArr[][8],int fullArrlength,int level){
    int i=1,j=0;
    for (i; i<fullArrlength;i++){
        if(fullArr[i][1] == level){
            for(int k=0;k<8;k++){
                levelArr[j][k] = fullArr[i][k];
            }        
        j++;  
        }
    }
    return j;
}

void testArr(long arr[][8]){
    printf("\n");
    for (int i = 0L; i < 8; i++){
        for (int j = 0L; j < 8; j++){
        printf(" %lu", arr[i][j]);
        }
        printf("\n");
    }
}

//*** Random number of pool
int randomOf(int poolSize){
    int r;
    if(poolSize>0){
        r =  rand() % poolSize;
        return r;
    }
     else {
         badRoute();
         return 0;
     }
}
