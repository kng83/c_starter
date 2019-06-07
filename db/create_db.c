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
    ptr = adv_malloc(sizeof mArr);

}

// saving pointer by key
void savePtrByKey(ptr_Arr* arr, char* key, char* value) {
    strcpy(arr->key, key);
    strcpy(arr->value, value);
}

