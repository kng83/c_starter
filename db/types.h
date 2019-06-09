#include<stdlib.h>

#define KEY_LENGTH 24
#define VALUE_LENGTH sizeof(size_t)  // typicall 8 in 64bit system
#define CELLS 10
#define MAX_KEY_ALLOCATION 62500

typedef struct key_val {
    char key[KEY_LENGTH];
    size_t *value_ptr;
} key_val;

typedef struct header{
    int max_key_allocation; //max number of keys
    size_t nr_of_bytes; //number of bytes
    int element_size; // single elements size in bytes
    int nr_of_elements;// nr of written elements
} header;