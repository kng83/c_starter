#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "adv_malloc.h"
#include "types.h"
#include "db_func.h"



//declarations
extern void* findKeyInArr(size_t* arr_ptr, int elm_size, char* key); 

int main() {
    ptr_Arr mArr[CELLS];
    size_t* ptr;
    ptr = adv_malloc(sizeof mArr);

    //Fake pointer area
    int one = 1;
    int two = 2;
    int three = 3;
    int four =4;
    size_t* ptr_one;
    size_t* ptr_two;
    size_t* ptr_three;
    size_t* ptr_four;
    ptr_one = (size_t*)&one;
    ptr_two = (size_t*)&two;
    ptr_three =(size_t*)&three;
    ptr_four = (size_t*)&four;

    char *keyTrueArr[10] = {"Bobo","Com","Czas","Dom","Gom","Kret","Net","Orka","Pies","Ziom"};
    char *keyFakeArr[21] = {
        "Ara","Bobos","Bzw","Cam","Czaz","Dama",
        "Drozd","Game","Got","Hret","Krat","Krew","Nat","Netia",
        "Olcha","Ospa","Pack","Piesek","Pwc","Zam","Zka"};

    printf("\nsize is %i", adv_allocated_size(ptr));
    strcpy(((ptr_Arr*)(ptr + 0))->key, "Bobo");
    strcpy(((ptr_Arr*)(ptr + 1))->key, "Com");
    strcpy(((ptr_Arr*)(ptr + 2))->key, "Czas");
    strcpy(((ptr_Arr*)(ptr + 3))->key, "Dom");
    strcpy(((ptr_Arr*)(ptr + 4))->key, "Gom");
    strcpy(((ptr_Arr*)(ptr + 5))->key, "Kret");
    strcpy(((ptr_Arr*)(ptr + 6))->key, "Net");
    strcpy(((ptr_Arr*)(ptr + 7))->key, "Orka");
    strcpy(((ptr_Arr*)(ptr + 8))->key, "Pies");
    strcpy(((ptr_Arr*)(ptr + 9))->key, "Ziom");

    // strcpy((ptr + 0)->key, "Bobo");
    // strcpy((ptr + 1)->key, "Com");
    // strcpy((ptr + 2)->key, "Czas");
    // strcpy((ptr + 3)->key, "Dom");
    // strcpy((ptr + 4)->key, "Gom");
    // strcpy((ptr + 5)->key, "Kret");
    // strcpy((ptr + 6)->key, "Net");
    // strcpy((ptr + 7)->key, "Orka");
    // strcpy((ptr + 8)->key, "Pies");
    // strcpy((ptr + 9)->key, "Ziom");

   // pointer assignment
    //  ((ptr_Arr*)(ptr + 0)).value_ptr = ptr_one;
    //  ((ptr_Arr*)(ptr + 1)).value_ptr = ptr_two;
    //  ((ptr_Arr*)(ptr + 2)).value_ptr = ptr_three;
    //  ((ptr_Arr*)ptr + 3)).value_ptr = ptr_four;


    //test true array 
    size_t *ret_ptr= NULL;
    printf("\nPointer starts at %p",ret_ptr);
    printf("\n----------------begin good------------------\n");
    for(int i=0;i<10;i++){
        printf("\nfinding key %s",keyTrueArr[i]);     
        ret_ptr = findKeyInArr(ptr, sizeof(ptr_Arr), keyTrueArr[i]);
        printf("\nPointer %p",ret_ptr);
        printf("\n---------------------\n");
    }
     printf("\n----------------begin fake------------------\n");
    for(int i=0;i<21;i++){
        printf("\nfinding key %s",keyFakeArr[i]);
        ret_ptr = findKeyInArr(ptr, sizeof(ptr_Arr), keyFakeArr[i]);
        printf("\nPointer %p",ret_ptr);
        printf("\n---------------------\n");
    }

    //Pointer print
    // printf("\nPtr_one %p",((ptr_Arr*)(ptr + 0))->value_ptr);
    // printf("\nPtr_two %p",((ptr_Arr*)(ptr + 1))->value_ptr);
    // printf("\nPtr_three %p",((ptr_Arr*)(ptr + 2))->value_ptr);
    // printf("\nPtr_four %p",((ptr_Arr*)(ptr + 3))->value_ptr);

    //print struct element
     printf("\nKey_one %s",((ptr_Arr*)(ptr + 0))->key);
     printf("\nKey_one %s",mArr[0].key);
     printf("\nKey_one %s",mArr[1].key);
     printf("\nKey_one %s",mArr[2].key);
}

