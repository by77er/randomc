#pragma once


typedef struct _Block Block;
struct _Block {
    Block* next_block;
    unsigned int size;
};

void* malloc(size_t bytes);
void free(void* pointer);

void _traverse_heap();

void _initialize_malloc();
size_t round_up(size_t num);