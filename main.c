#include <stdlib.h>
#include <stdio.h>

#include "dimacs_lib/dimacs.h"
#include "memory_lib/memory.h"

int main(){
    int l = 10;
    int* hehe = allock_array_int(l);
    int i;
    for(i = 0; i < l; i++){
        hehe[i] = l*i;
    }
    for(i = 0; i < l; i++){
        printf("%d\n", hehe[i]);
    }
    printf("L: %d\n", array_length_int(hehe));
    free_array_int(hehe);
}