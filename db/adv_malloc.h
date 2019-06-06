#include <stdlib.h>

//allocate memory
void* adv_malloc(size_t size);

//free memory
void adv_free(void* ptr);

//reallocate space
void* adv_realloc(void* ptr, size_t newSize);

//check size of allocated space
size_t adv_allocated_size(void* ptr);
