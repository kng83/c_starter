#include <stdlib.h>
#include "adv_malloc.h"
#include <stdio.h>
#include <string.h>

void* findKeyInArr(size_t* arr_ptr, int elm_size, char* key); 

// first take the length of array which is hidden in -1 element of array
// next check name of middle element of array
// when middle element has name is alphabetic smaller take new new middle
// element when programs find good key return value when key not found return
void* findKeyInArr(size_t* arr_ptr, int elm_size, char* key) {
    int lim_up = adv_allocated_size(arr_ptr) / elm_size;
    int lim_down = 0;
    int middle_element;
    int check = 1;
    size_t* ret = NULL;
    while (check) {
        middle_element = (lim_up + lim_down) / 2;
        printf("\nthis is key %s and middle is %i",((ptr_Arr*)(arr_ptr + middle_element))->key,middle_element);
        check = strcmp(key, ((ptr_Arr*)(arr_ptr + middle_element))->key);
      
        // key found
        if (!check) {
            printf("\nfound");
            ret =  ((ptr_Arr*)(arr_ptr + middle_element))->value_ptr;
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
