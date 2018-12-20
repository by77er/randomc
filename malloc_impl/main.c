#include <stdio.h>
#include <stdlib.h>
#include "malloc.h"

int main(void) {
    _initialize_malloc();
    printf("Block header size: %lu bytes\n", sizeof(Block));

    char* too_big = (char*)malloc(1024);
    printf("Too large: %p\n", too_big);

    char* chars = (char*)malloc(128);
    free((void*)chars);

    char* chars2 = (char*)malloc(64);
    free((void*)chars2);

    char* chars3 = (char*)malloc(256);
    free((void*)chars3);

    char* chars4 = (char*)malloc(1);
    free((void*)chars4);

    _traverse_heap();

};
