#include <stddef.h>
#include <stdio.h>
#include "malloc.h"

static char mem[1024]; // 1024 byte array
static Block* FIRST_FREE_BLOCK;

void* malloc(size_t bytes) {
    size_t aligned_size = round_up(bytes);
    if (FIRST_FREE_BLOCK == NULL) { // no blocks avalable right now
        return NULL;
    }
    
    Block* current = FIRST_FREE_BLOCK;
    Block* last = NULL;
    while (current != NULL) { // through last free block
        // printf("Looking at block: %p (size %u)\n", current, current->size);
        if (current->size == aligned_size) { // just big enough for data
            printf("Found fitting block: %p\n", current);
            if (last == NULL) { // if the first block, replace first block
                FIRST_FREE_BLOCK = current->next_block;
            } else {
                last->next_block = current->next_block;
            }
            return (Block*)((char*)current + sizeof(Block));
        } else if (current->size >= sizeof(Block) + aligned_size) { 
            // big enough to hold data and at least a block header
            printf("Found block with extra space: %p (size %u)\n", current, current->size);
            Block* newBlock = (Block*)((char*)current + sizeof(Block) + aligned_size); // new block at offset
            newBlock->size = current->size - aligned_size - sizeof(Block); // set to remainder
            newBlock->next_block = current->next_block;
            current->size = aligned_size;
            printf("Resized current block %p (size %u)\n", current, current->size);
            printf("Created new block %p (size %u)\n", newBlock, newBlock->size);
            if (last == NULL) { // if the first block, replace first block
                FIRST_FREE_BLOCK = newBlock;
            } else {
                last->next_block = newBlock;
            }
            return (Block*)((char*)current + sizeof(Block));
        }
        last = current;
        current = last->next_block; // move up chain
    }
    return NULL; // found no blocks
};

void free(void* pointer) {
    Block* b = (Block*)((char*)pointer - sizeof(Block)); // convert
    printf("Freeing block %p (size %u)\n", b, b->size);
    b->next_block = FIRST_FREE_BLOCK; // set next to current first
    FIRST_FREE_BLOCK = b; // set as first
};

void _traverse_heap() {
    Block* address = (Block*)mem;
    printf("Heap base: %p\n", address);

    while ((char*)address < (char*)mem + 1024) { // through last free block
        printf("Block at %p with size %u\n", address, address->size);
        // now to find the next address
        address = (Block*)((char*)address + address->size + sizeof(Block));
    }
};

void _initialize_malloc() {
    FIRST_FREE_BLOCK = (Block*)mem;
    FIRST_FREE_BLOCK->size = 1024 - sizeof(Block); // 1024 - 16 for first block header
    FIRST_FREE_BLOCK->next_block = NULL;
};

size_t round_up(size_t num) {
    if (num % 16 == 0) {
        return num;
    } else {
        return num + 16 - num % 16;
    }
};