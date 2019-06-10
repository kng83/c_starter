#include <stdlib.h>
// #ifndef header 
//     #include "types.h"
//  #endif

//allocate memory
void* adv_malloc(size_t size);

//free memory
void adv_free(void* ptr);

//reallocate space
void* adv_realloc(void* ptr, size_t newSize);

//check size of allocated space
size_t adv_allocated_size(void* ptr);

/**from size_t will be computed some of header constans
 * hObj holds structure of header information about table
 * nr_of_reserved_Bytes is allocation size
 * type_size is single element size in Bytes
 * function returns pointer to first table element
 */
void *v_malloc(size_t nr_of_reserved_Bytes, int type_size);

//**free memory
void v_free(void* ptr);

//**max number of possible elements
int v_maxNrOfElements(void* ptr);

//**single element size
int v_elementSize(void* ptr);

//**actual nr of elements in table
int v_actualNrOfElements(void* ptr);

//**exprerimental support
int v_changeNrOfElements(void* ptr, int newElNumber);

//**Increment number of elements
int v_incElementNumber(void* ptr);

//** Decrement number of elements
int v_decElementNumber(void* ptr);

//** Push new element to table
void* v_pushElement(void* ptr, key_val* element, int position);

//** Remove element from table
void* v_removeElement(void* ptr, int position);





