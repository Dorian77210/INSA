#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <assert.h>

#include "mem.h"

int main()
{
    // initialize the allocator
    mem_init();
    // mem_show_heap();

    char *buffer;

    // for (int i = 0; i < 7; i++)
    // {
    //     buffer = mem_alloc(42);
    // }

    // for (int i = 0; i < 2; ++i)
    // {
    //     buffer = mem_alloc( 200 );
    //     assert(buffer);
    //     printf("%p\n", buffer);
    // }

    // for (int i = 0; i < 6; ++i)
    // {
    //     buffer = mem_alloc(42);
    //     assert(buffer != NULL);
    // }

    // mem_release(buffer);

    // buffer = mem_alloc(42);
    // assert(buffer != NULL);

    // buffer = mem_alloc(200);
    // mem_release(buffer);
    // assert(buffer != NULL);
    // buffer = mem_alloc(300);
    // mem_release(buffer);
    // assert(buffer != NULL);

    for (int i = 0; i < 2; ++i)
    {
        buffer = mem_alloc(42);
        assert(buffer != NULL);
    }

    // for (int i = 0; i < 12; ++i)
    // {
    //     buffer = mem_alloc(42);
    //     assert(buffer != NULL);
    // }

    mem_show_heap();
}
