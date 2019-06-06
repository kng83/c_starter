#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "adv_malloc.h"

#define KEY_LENGTH 24
#define VALUE_LENGTH sizeof(size_t) //typicall 8 in 64bit system
#define CELLS 4

typedef struct ptr_Arr {
    char key[KEY_LENGTH];
    char value[VALUE_LENGTH];
} ptr_Arr;

// Declarations
void savePtrByKey(ptr_Arr* arr, char* key, char* value);
void findKeyInArr(size_t* arr_ptr, int elm_size, char* key);

// Main
int main() {
    ptr_Arr mArr[CELLS];
    size_t* ptr;
    printf("\nthis is pth %p", ptr);
    ptr = adv_malloc(sizeof mArr);

    printf("\nsize is %i",adv_allocated_size(ptr));
    strcpy(((ptr_Arr*)(ptr + 0))->value , "Bobo");
    strcpy(((ptr_Arr*)(ptr + 1))->value , "Pies");
    strcpy(((ptr_Arr*)(ptr + 2))->value , "Dom");
    strcpy(((ptr_Arr*)(ptr + 3))->value , "Ziom");

    char val[10] = "Bobo";
    char key[10] = "kot";
    savePtrByKey(&mArr[0], key, val);
    printf("\nPrint some answers %s", (&mArr[0])->value);
    findKeyInArr(ptr,sizeof(ptr_Arr),val);
}

// saving pointer by key
void savePtrByKey(ptr_Arr* arr, char* key, char* value) {
    strcpy(arr->key, key);
    strcpy(arr->value, value);
}

//
void findKeyInArr(size_t* arr_ptr, int elm_size, char* key){
    //first take the length of array which is hidden in -1 element of array
    //next check name of middle element of array 
    //when middle element has name is alphabetic smaller take new new middle element
    //when programs find good key return value
    //when key not found return -1

    //length 

    int middleElement = (adv_allocated_size(arr_ptr)/elm_size)/2;
    int lastElement = adv_allocated_size(arr_ptr)/elm_size;

    long middlePosition = middleElement * elm_size;
    printf("\nlenght is %i",middleElement);
    printf("\nMiddlePosition is %lu",middlePosition);
    printf("\nWhat is in middle position %s",((ptr_Arr*)(arr_ptr + middleElement))->value);

    int ans = strcmp(key,((ptr_Arr*)(arr_ptr + middleElement))->value);
    printf("\n Compare %i",strcmp("Bobol","Bobos"));
    printf("\n Compare %i",strcmp("Bobos","Bobo"));

    int m_element = middleElement;
    int l_element = lastElement;
    int check = 0;
    char answer[15];
    while(check = strcmp(key,((ptr_Arr*)(arr_ptr + m_element))->value)){
        printf("\nelement value %i, last element %i , check %i",m_element,l_element,check);
        //break condition if there is no elements to search
        if(m_element == 0 || m_element == lastElement){
            strcpy(answer,"key");
            break;
        }
        else if(check < 0){
          m_element/=2;
          continue;
        }
        else if(check >0){
            m_element += (l_element - m_element)/2;
            continue;
        }
        else if(check==0){
            strcpy(answer,"key");
            break;
        }
       
       break;
    }
     printf("\nthere is check %s",answer);
}
