#include<stdlib.h>

#define KEY_LENGTH 24
#define VALUE_LENGTH sizeof(size_t)  // typicall 8 in 64bit system
#define CELLS 10

typedef struct ptr_Arr {
    char key[KEY_LENGTH];
    size_t *value_ptr;
} ptr_Arr;