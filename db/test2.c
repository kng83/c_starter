#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "types.h"
#include "adv_malloc.h"
#include "db_func.h"

// declarations
extern void* findKeyInArr(key_val* arr_ptr, char* key);
extern int pushKeyPtrTooArr(key_val* arr_ptr, char* key, size_t value);


int main() {
    size_t* ptr;
    key_val* ptr2;
    header hObj;
    ptr2 = v_malloc(2000000,sizeof(key_val));

    // Fake pointer area
    int one = 1;
    int two = 2;
    int three = 3;
    int four = 4;
    size_t* ptr_one;
    size_t* ptr_two;
    size_t* ptr_three;
    size_t* ptr_four;
    size_t five;
    ptr_one = (size_t*)&one;
    ptr_two = (size_t*)&two;
    ptr_three = (size_t*)&three;
    ptr_four = (size_t*)&four;

    char* keyTrueArr[10] = {"Bobo", "Com", "Czas", "Dom",  "Gom",
                            "Kret", "Net", "Orka", "Pies", "Ziom"};
    char* keyFakeArr[21] = {"Ara",   "Bobos", "Bzw",   "Cam",  "Czaz", "Dama",
                            "Drozd", "Game",  "Got",   "Hret", "Krat", "Krew",
                            "Nat",   "Netia", "Olcha", "Ospa", "Pack", "Piesek",
                            "Pwc",   "Zam",   "Zka"};

    // strcpy((ptr2 + 0)->key, "Bobo");
    // strcpy((ptr2 + 1)->key, "Com");
    // strcpy((ptr2 + 2)->key, "Czas");
    // strcpy((ptr2 + 3)->key, "Dom");
    // strcpy((ptr2 + 4)->key, "Gom");
    // strcpy((ptr2 + 5)->key, "Kret");
    // strcpy((ptr2 + 6)->key, "Net");
    // strcpy((ptr2 + 7)->key, "Orka");
    // strcpy((ptr2 + 8)->key, "Pies");
    // strcpy((ptr2 + 9)->key, "Ziom");

    

    printf("\nelements is -------- %i",v_maxNrOfElements(ptr2));
    printf("\nelements is -------- %i",v_elementSize(ptr2));
    printf("\nelements is -------- %i",v_actualNrOfElements(ptr2));
    
    key_val el;
    strcpy(el.key,"Bilo");
    printf("\nthis is %s",el.key);
    v_pushElement(ptr2,&el,0);
  //  v_pushElement(ptr2,&el,1);

    printf("\nelements is -------- %i",v_actualNrOfElements(ptr2));
    printf("\nelements is -------- %s",(ptr2)->key);
    // pointer assignment
     (ptr2 + 0)->value_ptr = ptr_one;
     (ptr2 + 1)->value_ptr = ptr_two;
     (ptr2 + 2)->value_ptr = ptr_three;
     (ptr2 + 3)->value_ptr = ptr_four;

    goto omit;

    // test true array
    size_t* ret_ptr = NULL;
    printf("\nPointer starts at %p", ret_ptr);
    printf("\n----------------begin good------------------\n");
    for (int i = 0; i < 10; i++) {
        printf("\nfinding key %s", keyTrueArr[i]);
   //     ret_ptr = findKeyInArr(ptr2, keyTrueArr[i]);
        printf("\nPointer %p", ret_ptr);
        printf("\n---------------------\n");
    }
    printf("\n----------------begin fake------------------\n");
    for (int i = 0; i < 21; i++) {
        printf("\nfinding key %s", keyFakeArr[i]);
      //  ret_ptr = findKeyInArr(ptr2, keyFakeArr[i]);
        printf("\nPointer %p", ret_ptr);
        printf("\n---------------------\n");
    }

    // Pointer print
    printf("\nPtr_one %p",(ptr2+ 0)->value_ptr);
    printf("\nPtr_two %p",(ptr2 + 1)->value_ptr);
    printf("\nPtr_three %p",(ptr2 + 2)->value_ptr);
    printf("\nPtr_four %p",(ptr2 + 3)->value_ptr);

    // print struct element
    printf("\nKey_0 %s",(ptr2 + 0)->key);
    printf("\nKey_0 address %p", &(ptr2 + 0)->key);
    printf("\nKey_1 %s",(ptr2 + 1)->key);
    printf("\nKey_1 address %p", &(ptr2 + 1)->key);
    printf("\nKey_2 %s",(ptr2 + 2)->key);
    printf("\nKey_2 address %p", &(ptr2 + 2)->key);
     printf("\nKey_9 %s",(ptr2 + 9)->key);

omit:;
//pushKeyPtrTooArr(ptr2, "Zka",five );

// pushKeyPtrTooArr(ptr2, "Piko",five );
// pushKeyPtrTooArr(ptr2, "Bobos",five );
// printf("\nCompara %i",strcmp("Bobo","Bobl"));
//printf("\nthis is key value %s", (ptr2 + 9)->key );
//printf("\nthis is key value %s", (ptr2 + 10)->key );

printf("\ndoszlo");
}
