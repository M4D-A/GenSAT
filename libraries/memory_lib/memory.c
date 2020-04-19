#include "memory.h"
#include <stdlib.h>

int* allock_array_int(int length){
    int* array = malloc( (length + 1) * sizeof(int) );
    array[0] = length;
    return ++array;
}

int  array_length_int(int* array){
    return array[-1];
}


void free_array_int(int* array){
    free(--array);
}