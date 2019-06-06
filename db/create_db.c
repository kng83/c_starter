#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "adv_malloc.h"

#define KEY_LENGTH 24
#define VALUE_LENGTH sizeof(size_t)  // typicall 8 in 64bit system
#define CELLS 10

typedef struct ptr_Arr {
    char key[KEY_LENGTH];
    char value[VALUE_LENGTH];
} ptr_Arr;

// Declarations
void savePtrByKey(ptr_Arr* arr, char* key, char* value);
void* findKeyInArr(size_t* arr_ptr, int elm_size, char* key);

// Main
int main() {
    ptr_Arr mArr[CELLS];
    size_t* ptr;
 //   printf("\nthis is pth %p", ptr);
    ptr = adv_malloc(sizeof mArr);

    printf("\nsize is %i", adv_allocated_size(ptr));
    strcpy(((ptr_Arr*)(ptr + 0))->key, "Bobo");
    strcpy(((ptr_Arr*)(ptr + 1))->key, "Com");
    strcpy(((ptr_Arr*)(ptr + 2))->key, "Czas");
    strcpy(((ptr_Arr*)(ptr + 3))->key, "Dom");
    strcpy(((ptr_Arr*)(ptr + 4))->key, "Gom");
    strcpy(((ptr_Arr*)(ptr + 5))->key, "Kret");
    strcpy(((ptr_Arr*)(ptr + 6))->key, "Net");
    strcpy(((ptr_Arr*)(ptr + 7))->key, "Orka");
    strcpy(((ptr_Arr*)(ptr + 8))->key, "Pies");
    strcpy(((ptr_Arr*)(ptr + 9))->key, "Ziom");

    //char val[10] = "Dom";
    char key[10] = "Czas";
    findKeyInArr(ptr, sizeof(ptr_Arr), key);
}

// saving pointer by key
void savePtrByKey(ptr_Arr* arr, char* key, char* value) {
    strcpy(arr->key, key);
    strcpy(arr->value, value);
}

// first take the length of array which is hidden in -1 element of array
// next check name of middle element of array
// when middle element has name is alphabetic smaller take new new middle
// element when programs find good key return value when key not found return
void* findKeyInArr(size_t* arr_ptr, int elm_size, char* key) {
    int lim_up = adv_allocated_size(arr_ptr) / elm_size;
    int lim_down = 0;
    int middle_element = (int)(lim_up / 2);
    int check = 1;
    // Find key in binary tree
    printf("\nmiddle element is %i",middle_element);
    while (check) {
        printf("\nthis is key %s",((ptr_Arr*)(arr_ptr + middle_element))->key);
        check = strcmp(key, ((ptr_Arr*)(arr_ptr + middle_element))->key);
      
        // key found
        if (check == 0) {
            printf("\nfound");
            break;
        }
        // key not found
        else if (middle_element == 0 || middle_element == lim_up) {
            printf("\nnot Found");
            break;
        }
        // key is on the left
        else if (check < 0) {
            lim_up = middle_element; //aby zawezic gore
            middle_element = (middle_element - lim_down)/2 + lim_down;
            printf("\n<0 i %i", middle_element);
            continue;
        }
        // key is on the right
        else if (check > 0) {
            printf("\n>0 i %i", middle_element);
             lim_down = middle_element;
             middle_element = (lim_up + lim_down) / 2;
            continue;
        }
        break;
    }
}
