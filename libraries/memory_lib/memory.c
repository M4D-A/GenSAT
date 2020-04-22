#include "memory.h"
#include <stdlib.h>

int* array_int_allock(int length){
    int* array = malloc( (length + 1) * sizeof(int) );
    array[0] = length;
    return ++array;
}

int  array_int_length(int* array){
    return array[-1];
}


void array_int_free(int* array){
    free(--array);
}