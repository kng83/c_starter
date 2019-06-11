// example of swap generics
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void *swap(void *first, void *second, int size) {
    void *temp = (void *)malloc(size);
    memcpy(temp, first, size);
    memcpy(first, second, size);
    memcpy(second, temp, size);
    free(temp);
}

int main() {
    char a = 'A';
    char b = 'B';
    swap(&a, &b, sizeof(char));
    printf("After swap a = %c, b=  %c", a, b);
}