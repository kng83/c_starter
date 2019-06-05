#include <stdio.h>
#include <string.h>

#define KEY_LENGTH   32
#define VALUE_LENGTH  64 

typedef struct ptr_Arr {
    char key[KEY_LENGTH];
    char value[VALUE_LENGTH];
}ptr_Arr;


//Declarations
void savePtrByKey(ptr_Arr *arr,char *key, char * value);


//Main
int main() {
     ptr_Arr mArr;
     char val[10] ="bobo";
     char key[10]= "kot";
     savePtrByKey(&mArr,key,val);
     printf("Print some answers %s", (&mArr)->value);

}

void savePtrByKey(ptr_Arr *arr ,char * key, char * value) {
    strcpy(arr->key,key);
    strcpy(arr->value,value);
}
