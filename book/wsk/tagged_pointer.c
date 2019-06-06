#include <stdio.h>
#include <stdlib.h>

//size_t goes to the from of pointer
//this trick give size in first element which is not see by program or array
void* adv_malloc(size_t size) {
    size_t* ret = malloc(sizeof(size_t) + size);
    *ret = size;
    return ret + 1; //  return &ret[1];
}

void adv_free(void* ptr) { 
    free((size_t*)ptr - 1); 
}

void* adv_realloc(void* ptr, size_t newSize){
    size_t* ret = realloc(((size_t*)ptr -1), sizeof(size_t) + newSize);
    *ret = newSize;
    return ret + 1; //  return &ret[1];
}

//hack there is element before pointer
size_t allocated_size(void* ptr) { 
    return *((size_t*)ptr -1); //  return ((size_t*)ptr)[-1]; 
  
}

int main() {
    int* array = adv_malloc(sizeof(int) * 3);
    printf("1:%u\n", allocated_size(array));
    adv_realloc(array,(sizeof(int) * 6));
    printf("2:%u\n", allocated_size(array));   
    adv_free(array);
    return 0;
}