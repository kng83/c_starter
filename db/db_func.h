#include <stdlib.h>
#include "adv_malloc.h"
#include <stdio.h>
#include <string.h>

void* findKeyInArr(key_val* arr_ptr, char* key); 
int pushKeyPtrTooArr(key_val* arr_ptr, char* key, size_t value);
int findFreeKeyPosition(key_val* arr_ptr, char* key);

// first take the length of array which is hidden in -1 element of array
// next check name of middle element of array
// when middle element has name is alphabetic smaller take new new middle
// element when programs find good key return value when key not found return
void* findKeyInArr(key_val* arr_ptr, char* key) {
    int lim_up = adv_allocated_size(arr_ptr) / sizeof(*arr_ptr);
    int lim_down = 0;
    int middle_element;
    int check = 1;
    size_t* ret = NULL;
    while (check) {
        middle_element = (lim_up + lim_down) / 2;
        printf("\nthis is key %s and middle is %i",(arr_ptr + middle_element)->key,middle_element);
        check = strcmp(key, (arr_ptr + middle_element)->key);
      
        // key found
        if (!check) {
            printf("\nfound");
            ret =  (arr_ptr + middle_element)->value_ptr;
            break;
        }
        //key is on the left
        else if (check < 0) {
            if(middle_element == lim_down){
                printf("\nnot Found ,middle is %i",middle_element);
                break;
            }
            lim_up = middle_element; //aby zawezic gore
            printf("\nelement<middle_element i %i", middle_element);
            continue;
        }
        // key is on the right
        else if (check > 0) {
             middle_element ++;
             if(middle_element == lim_up){
                printf("\nnot Found ,middle is %i",middle_element);
                break;
             }
             lim_down = middle_element;
             printf("\nelement>middle_element i %i", middle_element);
            continue;
        }
        break;
    }
    return ret;
}

//**Find free key position if exists
int findFreeKeyPosition(key_val* arr_ptr, char* key) {
    int lim_up = adv_allocated_size(arr_ptr) / sizeof(*arr_ptr);
    int lim_down = 0;
    int middle_element;
    int check = 1;
    while (check) {
        middle_element = (lim_up + lim_down) / 2;
        check = strcmp(key, (arr_ptr + middle_element)->key);
      
        //key found
        if (!check)  return -1;

        //key is on the left
        else if (check < 0) {
            if(middle_element == lim_down) return middle_element;

            lim_up = middle_element; 
            continue;
        }
        // key is on the right
        else if (check > 0) {
             middle_element ++;
             if(middle_element == lim_up) return middle_element;

             lim_down = middle_element;
            continue;
        }
    }
    return -1;
}
//function checks if key exist if not create new record
//if key exist NULL is returned
int pushKeyPtrTooArr(key_val* arr_ptr, char* key, size_t value){
  int lim_up = adv_allocated_size(arr_ptr) / sizeof(*arr_ptr);
  int key_position = findFreeKeyPosition(arr_ptr,key);
  int allocatedSize = adv_allocated_size(arr_ptr);
  if(key_position>=0){
    //reallocate memory by one place up
    adv_realloc(arr_ptr, allocatedSize + sizeof(key_val));
    lim_up +=1;
    //move memory one place up
    memmove(arr_ptr + key_position +1,arr_ptr + key_position,(lim_up - key_position)*sizeof(key_val));
    //push new key value
    strcpy((arr_ptr + key_position)->key,key);
    (arr_ptr + key_position)->value_ptr = (size_t*)value;
  }
  return 0;
}
