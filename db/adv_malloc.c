#include <stdlib.h>

//allocate memory
void* adv_malloc(size_t size) {
    size_t* ret = malloc(sizeof(size_t) + size);
    *ret = size;
    return ret + 1; //  return &ret[1];
}

//free memory
void adv_free(void* ptr) { 
    free((size_t*)ptr - 1); 
}

//reallocate space
void* adv_realloc(void* ptr, size_t newSize){
    size_t* ret = realloc(((size_t*)ptr -1), sizeof(size_t) + newSize);
    *ret = newSize;
    return ret + 1; //  return &ret[1];
}

//check size of allocated space
size_t adv_allocated_size(void* ptr) { 
    return *((size_t*)ptr -1); //  return ((size_t*)ptr)[-1]; 
  
}
