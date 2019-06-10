#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// #ifndef header
#include "types.h"
//  #endif

// allocate memory
void* adv_malloc(size_t size) {
    size_t* ret = malloc(sizeof(size_t) + size);
    *ret = size;
    return ret + 1;  //  return &ret[1];
}

// free memory
void adv_free(void* ptr) { free((size_t*)ptr - 1); }

// reallocate space
void* adv_realloc(void* ptr, size_t newSize) {
    size_t* ret = realloc(((size_t*)ptr - 1), sizeof(size_t) + newSize);
    *ret = newSize;
    return ret + 1;  //  return &ret[1];
}

// check size of allocated space
size_t adv_allocated_size(void* ptr) {
    return *((size_t*)ptr - 1);  //  return ((size_t*)ptr)[-1];
}

void* v_malloc(size_t nr_of_reserved_Bytes, int type_size) {
    // allocate memory
    header* ret = malloc(nr_of_reserved_Bytes);
    ret->element_size = type_size;
    ret->max_key_allocation =
        (nr_of_reserved_Bytes - sizeof(header)) / type_size;
    ret->nr_of_bytes = nr_of_reserved_Bytes;  // increment if new value is added
    return ret + 1;
}

//**free memory
void v_free(void* ptr) { free((header*)ptr - 1); }

//**max number of possible elements
int v_maxNrOfElements(void* ptr) {
    return ((header*)ptr - 1)->max_key_allocation;
}

//**single element size
int v_elementSize(void* ptr) { return ((header*)ptr - 1)->element_size; }

//**actual nr of elements in table
int v_actualNrOfElements(void* ptr) {
    return ((header*)ptr - 1)->nr_of_elements;
}

//**exprerimental support
int v_changeNrOfElements(void* ptr, int newElNumber) {
    ((header*)ptr - 1)->nr_of_elements = newElNumber;
}

//**Increment number of elements
int v_incElementNumber(void* ptr) {
    return ((header*)ptr - 1)->nr_of_elements++;
}

//** Decrement number of elements
int v_decElementNumber(void* ptr) {
    return ((header*)ptr - 1)->nr_of_elements--;
}

//** Push new element to table
void* v_pushElement(void* ptr, key_val* element, int position) {
    int actualNrOfElement = v_actualNrOfElements(ptr);
    key_val* payload = ptr;

    if (actualNrOfElement < v_maxNrOfElements(ptr)) {
        v_incElementNumber(ptr);
        void* moved = memmove(
            (payload + position + 1),
            (payload + position),
            (size_t)((actualNrOfElement - position) * v_elementSize(ptr)));

        strcpy((payload + position)->key, element->key);
        (payload + position)->value_ptr = element->value_ptr;

        return moved;
    }
    return NULL;
}
//** Remove element from table
void* v_removeElement(void* ptr, int position) {
    int actualNrOfElement = v_actualNrOfElements(ptr);
    key_val* payload = ptr;

    if (actualNrOfElement < v_maxNrOfElements(ptr)) {
        
        void* moved = memmove(
            (payload + position),
            (payload + position + 1),
            (size_t)((actualNrOfElement - position) * v_elementSize(ptr)));

        v_decElementNumber(ptr);
        return moved;
    }
    return NULL;
}