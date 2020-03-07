#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <assert.h>
#include <unistd.h>
#include <sys/mman.h>

#include "mem.h"

void * heap_base = NULL;// first byte of the heap
void * heap_end  = NULL;// first byte beyond the heap

int mem_initialized = 0;

// initialize the memory manager
void mem_init(void)
{
    assert(mem_initialized == 0);

    // request memory from the kernel
    heap_base = mmap(NULL, 800, PROT_READ|PROT_WRITE,MAP_PRIVATE|MAP_ANONYMOUS,-1,0);
    assert(heap_base != MAP_FAILED);

    heap_end = heap_base + 800 ;

    // for(int i=0; i<5;i++)
    // {
    //     block_ptr = heap_base + 80*i;
    //     *( (int64_t*)block_ptr ) = 80;
    // }
    *( (int64_t*)heap_base ) = 800;
    *((int64_t*)(heap_base + 792)) = 800;

    mem_initialized = 1;
}

void * mem_alloc(int64_t length)
{
    assert(mem_initialized == 1);
    
    // compute actual size of block
    length = (length+7)/8*8; // round up to nearest multiple of 8
    length += 8;              // add space for the header
    length += 8;              // add the space for the footer

    // heap traversal
    void *  block_ptr;
    int64_t header;
    int64_t size;   
    char    flags;
    
    block_ptr = heap_base;
    while(block_ptr < heap_end)
    {
        header = *( (int64_t*)block_ptr );
        flags  = header & 0b111;  // keep only three least significant bits
        size = header & ~0b111;   // discard the three least significant bits

        if( (flags == 0 ) &&      // if current block is free, and
            (size >= length))     // is also large enough, then we have a winner
            break;

        // otherwise we move on to the next block
        block_ptr += size;
    }

    // if the heap  traversal reached this far, then it  means we have
    // found no suitable block, so we should return NULL
    if(block_ptr >= heap_end)
    {
        return NULL;
    }

    flags = 0b001; // mark block as taken
    header = length | flags;
    *((int64_t*)block_ptr ) = header; // write header back into the block
    *((int64_t*)(block_ptr + length - 8)) = header; // write footer 

    // create a partition in the current block$
    void *new_block = block_ptr + 8;

    header = (size - length) | 0b000;
    *((int64_t*)(block_ptr + length)) = header;

    return new_block;
}

void mem_release(void *ptr)
{
    assert( mem_initialized == 1);
    assert( ((int64_t)ptr % 8) == 0 ); // sanity check

    // TODO: your deallocation algorithm goes here

    int64_t header = *((int64_t *)(ptr - 8));
    header = header & ~0b111;
    *((int64_t *)(ptr - 8)) = header;
    *((int64_t*)(ptr + header)) = header;

    // fusion

    return;
}

void mem_show_heap(void)
{
    assert( mem_initialized == 1);
    
    void * block_ptr = heap_base;

    printf("heap_base = %p\n",heap_base);
    while(block_ptr < heap_end)
    {
        int64_t header = *( (int64_t*)block_ptr );
        char    flags  = header & 0b111;  //   keep only three least significant bits
        int64_t size   = header & ~0b111; // discard the three least significant bits
        int64_t footer = *((int64_t*)(block_ptr + size - 8));

        if( (size < 8) ||
            (size%8 != 0) )
        {
            printf("error: block at %p has incorrect size %ld\n",block_ptr,size);
            exit(1);
        }

        printf("  block at %p: header=0x%08lx size=%ld flags=%d (%s) footer=0x%08lx\n",
               block_ptr,header,size,flags,
               (flags ? "taken" : "free"), footer
               );

        block_ptr += size; // move on to next block
    }

    printf("heap_end = %p\n",heap_end);

    //sanity check: a full heap traversal should reach *exactly* the end
    assert( block_ptr == heap_end); 
}
