#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../types.h"
#include "../adv_malloc.h"
#include "../db_func.h"

// declarations
extern void* findKeyInArr(key_val* arr_ptr, char* key);
extern int pushKeyPtrTooArr(key_val* arr_ptr, char* key, size_t value);
extern void* v_removeElement(void* ptr, int position);


int main() {
    key_val* ptr2;
    ptr2 = v_malloc(2000000,sizeof(key_val));

    // Fake pointer area
    int one = 1;
    int two = 2;
    int three = 3;

    //declare keys
    key_val el,el2,el3;
    strcpy(el.key,"Bilo");
    strcpy(el2.key,"Momo");
    strcpy(el3.key,"three");

    el.value_ptr = (size_t*)&one;
    el2.value_ptr = (size_t*)&two;

    //push keys
    v_pushElement(ptr2,&el,0);
    v_pushElement(ptr2,&el2,1);
    v_pushElement(ptr2,&el3,2);


    printf("\nelements is -------- %i",v_actualNrOfElements(ptr2));
    printf("\nelement 0 is -------- %s",(ptr2)->key);
    printf("\nelement 1 is -------- %s",(ptr2+1)->key);
    printf("\nelement 2 is -------- %s",(ptr2+2)->key);
    printf("\nelement 0 value is -------- %i",*(ptr2)->value_ptr);
    printf("\nelement 1 value is  -------- %i",*(ptr2+1)->value_ptr);

    //remove element 
    v_removeElement(ptr2,0);
    printf("\nremove elements is -------- %s",(ptr2)->key);
    printf("\nremove elements is -------- %s",(ptr2+1)->key);
    printf("\nremove elements is -------- %s",(ptr2+2)->key);

    //check numbers
    printf("\nelements is -------- %i",v_maxNrOfElements(ptr2));
    printf("\nelements is -------- %i",v_elementSize(ptr2));
    printf("\nelements is -------- %i",v_actualNrOfElements(ptr2));
 
}
