#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define QUESTION_MAX 100
#define ANSWER 100
#define TEXT_NUMBER 5
#define MAX_LINE 512

//Declarations;
void addQuestion();
void badRoute();
int checkLastQuestionNumber(FILE *fp);

typedef struct DataModel
{
    char question_number[TEXT_NUMBER];
    char question_level[TEXT_NUMBER];
    char question_description[QUESTION_MAX];
    char fake_answer_1[ANSWER];
    char fake_answer_2[ANSWER];
    char fake_answer_3[ANSWER];
    char correct_answer_4[ANSWER];
} DataModel;

void addQuestion()
{

    printf("\n[2] dodaj pytanie");

    FILE *fp; //na plik
    DataModel Question;
    
    //**Check data file;
    if ((fp = fopen("data.csv", "a+")) == NULL)
    {
        fprintf(stdin, "Nie moge otworzyc pliku \" words \".\n");
        exit(1);
    }

    checkLastQuestionNumber(fp);

    puts("\nWpisz poziom pytania:");
    if (!gets(Question.question_level))
        badRoute();

    puts("\nWpisz tresc pytania");
    if (!gets(Question.question_description))
        badRoute();

    puts("\nWpisz pierwsza bledna odpowiedz");
    if (!gets(Question.fake_answer_1))
        badRoute();

    puts("\nWpisz druga bledna odpowiedz");
    if (!gets(Question.fake_answer_2))
        badRoute();

    puts("\nWpisz trzecia bledna odpowiedz");
    if (!gets(Question.fake_answer_3))
        badRoute();

    puts("\nWpisz poprawna odpowiedz");
    if (!gets(Question.correct_answer_4))
        badRoute();

    //Wydrukuj to co napisales do pliku
    fprintf(fp, "%s;%s;%s;%s;%s;%s",
            Question.question_level,
            Question.question_description,
            Question.fake_answer_1,
            Question.fake_answer_2,
            Question.fake_answer_3,
            Question.correct_answer_4);
}

int checkLastQuestionNumber(FILE *fp){
    char ch;
    long counter, end_position, new_line_position, first_semicolon_in_line;
    fseek(fp, 0L, SEEK_END);  //na koniec pliku
    end_position = ftell(fp); //pozycja na koncu

    for (counter = 1; counter <= end_position; counter++){
        //**Find last semicolon and of line
        fseek(fp, -counter, SEEK_END);
        ch = getc(fp);
        if(ch== ';'){
            first_semicolon_in_line = end_position - counter;
        }
        if (ch == '\n'){
            new_line_position = end_position - counter;
            break;
        }
    }

    printf("\nfirst semicollon %lu", first_semicolon_in_line);
    printf("\nPosition of new line %lu", new_line_position);
    printf("\nto koniec pliku %i", end_position);

    //***Ustw wskaznik na koniec pliku
    fseek(fp, 0L, SEEK_END); 
    return 0;
}

void badRoute()
{
    printf("\nSomething goes wrong");
    exit(3);
}