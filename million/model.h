#include <stdio.h>
#include <stdlib.h>

#define QUESTION_MAX 100
#define ANSWER 100
#define TEXT_NUMBER 5

//**Declarations
void badRoute();

typedef struct DataModel
{
    char question_number[TEXT_NUMBER];
    char question_level[TEXT_NUMBER];
    char question_description[QUESTION_MAX];
    char correct_answer_0[ANSWER];
    char fake_answer_1[ANSWER];
    char fake_answer_2[ANSWER];
    char fake_answer_3[ANSWER];
} DataModel;

void badRoute(){
    printf("\nSomething goes wrong");
    exit(3);
}