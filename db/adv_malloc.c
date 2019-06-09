#include <stdlib.h>
#include <stdio.h>
#include <string.h>
// #ifndef header 
#include "types.h"
//  #endif

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

void *v_malloc(header hObj,size_t nr_of_reserved_Bytes, int type_size){
    hObj.element_size = type_size;
    hObj.max_key_allocation = (nr_of_reserved_Bytes - sizeof(header))/type_size;
    hObj.nr_of_bytes = nr_of_reserved_Bytes; //increment if new value is added

    //allocate memory
    header* ret = malloc(nr_of_reserved_Bytes);
    return ret + 1 ;
}

//**free memory
void v_free(void* ptr) { 
    free((header*)ptr -1); 
}

//**max number of possible elements
int v_maxNrOfElements(void* ptr) { 
    return  ((header*)ptr -1)->max_key_allocation;
}

//**single element size
int v_elementSize(void* ptr) { 
    return  ((header*)ptr -1)->element_size;
}

//**actual nr of elements in table
int v_actualNrOfElements(void* ptr){
    return  ((header*)ptr -1)->nr_of_elements;
}

//**exprerimental support
int v_changeNrOfElements(void* ptr, int newElNumber){
    ((header*)ptr-1)->nr_of_elements = newElNumber;
}

//**Increment number of elements
int v_incElementNumber(void* ptr){
    return ((header*)ptr-1)->nr_of_elements++;
}

//** Decrement number of elements
int v_decElementNumber(void* ptr){
    return ((header*)ptr-1)->nr_of_elements--;
}

//** Push new element to table
void* v_pushElement(void* ptr, key_val* element, int position){
    int actualNrOfElement = v_actualNrOfElements(ptr);
    if(actualNrOfElement < v_maxNrOfElements(ptr)){
    void* moved = memmove(
            (key_val*)(ptr + position + 1),
            (key_val*)(ptr + position),
            (actualNrOfElement - position) * v_elementSize(ptr));
    v_incElementNumber(ptr);
    return moved;
    }
    return NULL;
}
//** Remove element from table
void* v_removeElement(void* ptr, key_val* element, int position){
   // return NULL;
}