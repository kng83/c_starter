#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>


#define MAX_LINE 512

//Declarations;
void addQuestion();

int checkLastQuestionNumber(FILE *fp);
void checkForInputIsNumber(char *_Buffer);
void checkForInputIsString(char *_Buffer);
extern void clearScreen(void);



void addQuestion()
{
    FILE *fp; //na plik
    DataModel Question;
    
    printf("\n[2]******* Dodaj pytanie ***************************************");
    //**Check data file;

    if ((fp = fopen("data.csv", "a+")) == NULL){
        fprintf(stdin, "Nie moge otworzyc pliku \" words \".\n");
        badRoute();
    }
   
   int currentQuestion  = checkLastQuestionNumber(fp) + 1;
   if(currentQuestion<0) badRoute();

    printf("\nWpisujesz pytanie nr %i",currentQuestion);

    //convert question_number to char
    sprintf(Question.question_number,"%d",currentQuestion);

    puts("\nWpisz poziom pytania:");
    checkForInputIsNumber(Question.question_level);

    puts("\nWpisz tresc pytania");
    checkForInputIsString(Question.question_description);

    
    puts("\nWpisz poprawna odpowiedz:");
    checkForInputIsString(Question.correct_answer_0);

    puts("\nWpisz bledna odpowiedz nr 1:");
    checkForInputIsString(Question.fake_answer_1);

    puts("\nWpisz bledna odpowiedz nr 2:");
    checkForInputIsString(Question.fake_answer_2);
    
    puts("\nWpisz bledna odpowiedz nr 3:");
    checkForInputIsString(Question.fake_answer_3);

    //Wydrukuj to co napisales do pliku
    fprintf(fp, "\n%s;%s;%s;%s;%s;%s;%s;",
            Question.question_number,
            Question.question_level,
            Question.question_description,
            Question.correct_answer_0,
            Question.fake_answer_1,
            Question.fake_answer_2,
            Question.fake_answer_3
            );

    printf("\nDodano pytanie.Czy chesz kontynuowac (y/n).");
      if(fclose(fp)!=0){
        fprintf(stdin, "Nie moge zamknac pliku \" data \".\n");
        badRoute();
      }

    //**Jesli chesz dodawac pytania to daj y
      char  con[TEXT_NUMBER];
      if(gets(con)!=NULL && *con =='y'){
          addQuestion();
      }
}

//todo make something with trailing spaces at the end of file
int checkLastQuestionNumber(FILE *fp){
    char ch;
    long counter, end_position, new_line_position, first_semicolon_in_line;
    fseek(fp, 0L, SEEK_END);  //na koniec pliku
    end_position = ftell(fp); //pozycja na koncu

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
   // printf("\n%lu oraz %lu oraz %lu",first_semicolon_in_line,new_line_position,counter);

    //**Finding question number in csv file
    char q_array[TEXT_NUMBER];
    char *q_number = q_array;
    for (int i=0;i<=first_semicolon_in_line-new_line_position;i++){
        fseek(fp, new_line_position + i,SEEK_SET); 
        *(q_number+i) =getc(fp);
    }

    //***Set pointer at the end of the file
    fseek(fp, 0L, SEEK_SET);  
    return atoi(q_number);
}

//checking if input is a number
void checkForInputIsNumber(char *_Buffer){
    char temp[TEXT_NUMBER];
    char *ptr_temp = temp;
    ptr_temp = gets(_Buffer);
    if(ptr_temp==NULL || atoi(ptr_temp)<=0)
    badRoute();
}

//checking if input is a string
void checkForInputIsString(char *_Buffer){
    if(gets(_Buffer)==NULL || *_Buffer=='\0')
    badRoute();
}