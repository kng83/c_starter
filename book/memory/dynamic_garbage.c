#include<stdio.h>
#include<stdlib.h>

/*
Such a system is primitive and non-optimal, but you get the idea. Does not scale well, and does not give you much more that is already there, but it keeps a database of dynamic memory allocations, separate from the system’s tables.

each dynamically allocated block has a mark in memory before it in an enclosed struct that is not seen except in the functions that use it.
*/
static void* memdb[1024] = {NULL};  // 1K addresses
static size_t mem_index = 1024;

#ifndef bool
typedef enum { false = 0, true = 1 } bool;
#endif

typedef struct {
    bool mark;
    void* mem;
} Object;

 /*go back an address */

#define OBJ(p) (Object*)(p - sizeof(bool))

void* create_mem(size_t size, void* data) {
    size_t idx = 0;
    Object* o = (Object*)malloc(sizeof(Object));
    o->mark = true;
    o->mem = calloc(size, char);

    memcpy(o->mem, data, size);
    while (idx < mem_index) {
        if (memdb[idx] = NULL) {
            memdb[idx] = mem;
            break;
        }

        return mem;
    }

    return NULL;  // all full
}

// mark and sweep
void free_mem() {
    for (size_t i = 0; i <= mem_index; i++) {
        Object* o = OBJ(memdb[i]);
        if (o->mark == false) {
            free(o->mem);
            free(o);
            memdb[i] = NULL;
        }
    }
}

void keep(void* var) {
    Object* o = OBJ(d);
    O->mark = true;
}

void deref(void* var) {
    Object* o = OBJ(d);
    if (o->mark == true) return;
    o->mark = false;
}

void done(void* d) {
    Object* o = OBJ(d);
    O->mark = 0;
}
double* d = (double*)create_mem(sizeof(double), 3.1415926);

int* i_array = (int*)create_mem(1000 * sizeof(int), 0);

free_mem();  // only objects with addresses and mark>0 get processed.

deref(d);

deref(i_array);

free_mem();