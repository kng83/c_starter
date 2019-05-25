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
int mapperArray(FILE *fp, long arr[][8]);
void testTwoDimArray(long arr[][8]);
int questionsPerLevelArr(long levelArr[][8], long mappedArr[][8], int mappedArrlength, int level);
int randomOf(int);
long *takeRandomElement(long levelArr[][8], int);
void testArray(long arr[8]);
int readQuestion(FILE *fp, long positionArr[8], char cont [5][100]);
int * makeArrOfRandom(const int startNumber ,const int endNumber);
int printQuestion(char cont[5][100]);
void testIntArray(int * arr,int size);
int generateLevelQuestion( FILE *fp, long mappedArr[][8],int questionLines, int level);
extern void start(void);
extern void clearScreen(void);

//**Main
void beginGame()
{
    initializeRandom();
    playGame();
}

void playGame()
{
    printf("\n***************************************************");
    printf("\n**************** Rozpoczynamy gre *****************");
    printf("\n***************************************************");
    printf("\n\n");

    FILE *fp; //file pointer

    //**Check data file;
    if ((fp = fopen("data.csv", "r")) == NULL)
    {
        fprintf(stdin, "Nie moge otworzyc pliku \" words \".\n");
        badRoute();
    }
    long mappedArr[MAX_QUESTION_LIST][8];
    long levelArr[MAX_QUESTION_LIST][8];
    int questionLines = mapperArray(fp, mappedArr);
    int level, correct;

    //*** Game loop
    for (level = 1 ,correct =0; level <= MAX_LEVEL;){
       correct = generateLevelQuestion(fp,mappedArr, questionLines,level);
       if(correct==1){
           level++;
           continue;
       }else{
           break;           
       }
    }
    if(correct){
        //show winner banner;
        return start();
    } else{
       // go back to main menu
        clearScreen();
        printf("Powrot do menu");
        return start();
    }
}
int generateLevelQuestion( FILE *fp, long mappedArr[][8],int questionLines, int level){
     long levelArr[MAX_QUESTION_LIST][8];
     int questionPerLevel = questionsPerLevelArr(levelArr, mappedArr, questionLines, level);
     
     printf("\n******** Pytanie nr %i wylosowane z puli [%i] *******",level, questionPerLevel);
     printf("\n");

     //*** Take random question based level
     long *questStats;
     questStats = takeRandomElement(levelArr, questionPerLevel);

     //***Read question from csv file
     char cont[5][100];
     readQuestion(fp, questStats,cont);
     //***Print and answare the question
     return printQuestion(cont);
}

//***Take question from file
int readQuestion(FILE *fp, long positionArr[8], char cont[5][100])
{
    long counter;
    long shortCounter = 0;
    int i,j;

    for ( i = 2, j=0; i <= 6; i++,j++){
        shortCounter = 0;
        for (counter = positionArr[i]; counter < positionArr[i+1] - 1;){
            fseek(fp, counter, 0L);
            cont[j][shortCounter] = getc(fp);
            shortCounter++;
            counter++;
        }
         cont[j][shortCounter] ='\0';
    }
    return 0;
}
//***printing answer of the question with random positions. Returns 0 if correct;
int printQuestion(char cont[5][100]){
    int * arr5;
    arr5 = makeArrOfRandom(1,5);
    char * questionA, *questionB, *questionC , *questionD, *answer;

    questionA = cont[arr5[0]];
    questionB = cont[arr5[1]];
    questionC = cont[arr5[2]];
    questionD = cont[arr5[3]];

    //Tu pisz
    printf("\n\t%s", cont[0]);
    printf("\nA: %s",questionA);
    printf("\nB: %s",questionB);
    printf("\nC: %s",questionC);
    printf("\nD: %s",questionD);
    
    //Pick answer 
    printf("\n\nTwoja odpowiedz to:");
    char  text[TEXT_NUMBER];
    int correct =0;
      if(gets(text)!=NULL){
          if((text[0]=='a' || text[0]=='A') && questionA == cont[1]){
              printf("\n\tBrawo!!! A to dobra odpowiedz.");
              correct = 1;
          }
          else if((text[0]=='b' || text[0]=='B') && questionB == cont[1]){
              printf("\n\tBrawo!!! B to dobra odpowiedz.");
              correct = 1;
          }
          else if((text[0]=='c' || text[0]=='C') && questionC == cont[1]){
              printf("\n\tBrawo!!! C to dobra odpowiedz.");
              correct = 1;
          }
          else if((text[0]=='d' || text[0]=='D') && questionD == cont[1]){
              printf("\n\tBrawo!!! D to dobra odpowiedz.");
              correct = 1;
          }else{
               printf("\nPrzykro mi to zla odpowiedz.");
               printf("\nPrawidlowa odpowiedz to %s.",cont[1]);
               correct = 0;
          }
    }else{
        printf("\nBrak wpisanego tekstu");
        correct = 0;
    }
    printf("\n");
    return correct;

}
//** Random initialization
void initializeRandom(){
    srand(time(NULL)); // Initialization, should only be called once.
}

//***Make array with answers position base on index and level;
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

    for (counter; counter <= end_position; counter++)
    {
        //**Find last semicolon and of line
        fseek(fp, counter, 0L);
        ch = getc(fp);

        if (ch != ';' || ch != '\n')
        {
            content[shortCounter] = ch;
            shortCounter++;
        }
        if (ch == ';')
        {
            colonCounter++;
            shortCounter = 0; //aby poczatek by w zerze

            //index
            if (colonCounter == 1)
            {
                arr[newLineCounter][0] = atol(content);
            }
            //pick up level
            if (colonCounter == 2)
            {
                arr[newLineCounter][1] = atol(content); //aby dac poziom pytania
                arr[newLineCounter][2] = counter + 1;   //aby wychwycici poczatek pytan
            }
            //catch up all positions
            if (colonCounter > 2)
            {
                arr[newLineCounter][colonCounter] = counter + 1;
            }
        }
        if (ch == '\n')
        {
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
int questionsPerLevelArr(long levelArr[][8], long mappedArr[][8], int mappedArrlength, int level)
{
    int i = 1, j = 0;
    for (i; i <= mappedArrlength; i++)
    {
        if (mappedArr[i][1] == level)
        {
            for (int k = 0; k < 8; k++)
            {
                levelArr[j][k] = mappedArr[i][k];
            }
            j++;
        }
    }
    return j;
}
//*** make random numbers
 int * makeArrOfRandom(const int startNumber ,const int endNumber){
     static int arr[100];
     static  * arr_pointer;
     arr_pointer =arr;
     int i =0;
     int length;
     length = endNumber - startNumber;
     
     while (1){
        arr[i] = (rand() % length) + startNumber;
        if(i == 0){
            i++;
            goto con_while;
        }
        //Continous searching for new number
        for (int j=0;j<i;j++){
            if(arr[j] == arr[i]) goto  con_while;
        }
          
        //increment loop 
        i++;
        //Go away;
        if(i==length){
            break;
        }
        con_while:continue;
    }
    return arr_pointer;
 }

//*** Take random array element
long *takeRandomElement(long levelArr[][8], int arrlength){
    static long arr[8];
    int r = randomOf(arrlength);
    for (int i = 0; i < 8; i++){
        arr[i] = levelArr[r][i];
    }
    return arr;
}
//*** Random number of pool
int randomOf(int poolSize){
    if (poolSize > 0){
        return rand() % poolSize;
    }
    else{
        badRoute();
        return 0;
    }
}

//**Test single dimension array
void testArray(long arr[8]){
    printf("\n");
    for (int i = 0; i < 8; i++){
        printf("%lu;", arr[i]);
    }
}

//**Test single dimension array
void testIntArray(int * arr,int size){
    printf("\n");
    for (int i = 0; i < size; i++){
        printf("%i;", arr[i]);
    }
}
//**Test 2 dimension array
void testTwoDimArray(long arr[][8]){
    printf("\n");
    for (int i = 0L; i < 8; i++)
    {
        for (int j = 0L; j < 8; j++)
        {
            printf("%lu", arr[i][j]);
        }
        printf("\n");
    }
}