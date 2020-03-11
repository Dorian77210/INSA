#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <semaphore.h>
#include <pthread.h>
#include <unistd.h>

#include "bag.h"

bag_t * bb_create(int size)
{
    assert(size > 0);
    
    bag_t *bag=malloc(sizeof(bag_t));
    assert(bag != NULL);

    bag->elem = malloc( size * sizeof(void*));
    assert(bag->elem);

    bag->size  = size;
    bag->count = 0;
    bag->is_closed = 0;

    sem_init(&bag->empty, 0, bag->size);
    sem_init(&bag->available, 0, 0);
    sem_init(&bag->exclusion, 0, 1);

    return bag;
}

void bb_add(bag_t * bag, void * element)
{
    assert(bag != NULL);                 // sanity check

    sem_wait(&bag->empty); // decrement the available tokens

    sem_wait(&bag->exclusion);

    assert( bag-> is_closed == 0 );   // adding to a closed bag is an error
    assert( bag->count < bag->size ); // sanity check
    bag->elem[bag->count] = element;
    bag->count += 1;

    sem_post(&bag->available); // increment the available tokens

    sem_post(&bag->exclusion);
}

void * bb_take(bag_t *bag)
{
    assert(bag != NULL); // sanity check

    sem_wait(&bag->available); // decrement the available tokens
    if ( bag->is_closed && bag->count == 0) 
    {
        sem_post(&bag->available);
        return NULL;
    }

    sem_wait(&bag->exclusion);

    assert( bag->count > 0); // sanity check
    bag->count -= 1;
    void *r = bag->elem[bag->count];

    usleep(10);// artificial delay to increase the occurence of race conditions
    sem_post(&bag->empty); // increment the empty tokens
    sem_post(&bag->exclusion);

    return r;
}

void bb_close(bag_t *bag, int N)
{
    sem_wait(&bag->exclusion);
    bag->is_closed = 1;
    sem_post(&bag->exclusion);

    for ( int i = 0; i < N; ++i)
    {
        sem_post(&bag->available);
    }
}
