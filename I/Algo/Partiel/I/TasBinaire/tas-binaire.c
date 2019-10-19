#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    int allocated; /* current allcoation of array */
    int filled;    /* number of items present in the binheap */
    int *array;    /* array of values */
} BinaryHeap;

int parent ( int index ) 
{
    return ( index - 1 ) / 2;
}

int has_parent ( int index ) 
{
    int tmp = parent ( index );
    return tmp >= 0;
}

int right_child ( int index ) 
{
    return ( 2 * index ) + 2;
}

int has_right_child ( int index, int size ) 
{
    int tmp = right_child ( index );
    return tmp <= size;
}

int left_child ( int index ) 
{
    return ( 2 * index ) + 1;
}

int has_left_child ( int index, int size ) 
{
    int tmp = left_child ( index );
    return tmp <= size;
}

void swap ( int *a, int *b ) 
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

int max ( int *array, int left, int right ) 
{
    return array [ left ] <= array [ right ]
        ? right
        : left;
}

/* Init allocates the structure BinaryHeap and
 * also the membre array with the given size 
 * it also fill allocated (size) and intializes 
 * filled to 0 */
BinaryHeap *Init(int size);

/* InsertValue insert value into the binary heap
 * the array is reallocated if necessary (allocated changed 
 * with respect to the new size )
 * filled is incremented by 1 */
void InsertValue(BinaryHeap *heap, int value);

/* ExtractMAx returns 0 if the binary heap is empty
 * otherwise it return 1 and fills *val with the maximum 
 * value present in the binary heap
 * filled is decremented by 1  and the max value is removed
 * from the binary heap */
int ExtractMax(BinaryHeap *heap, int *val);

/* Destroy frees the structure and the array */
void Destroy(BinaryHeap *heap);

int main(void)
{
    char lecture[100];
    int val;
    BinaryHeap *heap;
    heap = Init(10);

    fscanf(stdin, "%99s", lecture);
    while (strcmp(lecture, "bye") != 0)
    {
        if (strcmp(lecture, "insert") == 0)
        {
            fscanf(stdin, "%99s", lecture);
            val = strtol(lecture, NULL, 10);
            InsertValue(heap, val);
        }
        else if (strcmp(lecture, "extract") == 0)
        {
            if (ExtractMax(heap, &val))
            {
                printf("%d\r\n", val);
            }
        }
        fscanf(stdin, "%99s", lecture);
    }
    Destroy(heap);
    return 0;
}

BinaryHeap *Init(int size)
{
    BinaryHeap *heap;
    heap = (BinaryHeap*)malloc(sizeof(BinaryHeap));
    if ( !heap ) 
    {
        fprintf ( stderr, "Error when mallocing for the binary heap \n" );
        return NULL;
    }

    heap->allocated = size;
    heap->array = (int*)malloc(size * sizeof(int));
    if ( !heap->array ) 
    {
        fprintf ( stderr, "Error when mallocing for the array\n" );
        return NULL;
    }

    heap->filled = 0x0;
    return heap;
}

void InsertValue(BinaryHeap *heap, int value)
{
    int parent_index, current_index, current_value, tmp;
    
    if ( heap->allocated == heap->filled ) 
    {
        heap->allocated *= 2;
        heap->array = ( int* ) realloc ( heap->array, heap->allocated );
    }

    heap->array [ heap->filled ] = value;

    current_index = heap->filled;
    current_value = heap->array [ current_index ];

    while ( 1 ) 
    {
        parent_index = parent ( current_index );
        tmp = heap->array [ parent_index ];
        if ( tmp < current_value )
        {
            // le parent actuel doit etre remplace
            swap ( &heap->array [ parent_index ], &heap->array [ current_index ] );
            current_index = parent_index;
            current_value = heap->array [ current_index ];
        } else
        {
            break;
        }
    }

    heap->filled++;
}

int ExtractMax(BinaryHeap *heap, int *res)
{
    if ( heap->filled == 0 ) return 0;
    int has_left, has_right, current_index, size, left_index, right_index;
    int max_index;

    *res = heap->array [ 0 ];
    heap->filled--;
    heap->array [ 0 ] = heap->array [ heap->filled ];

    current_index = 0;
    size = heap->filled;

    while ( 1 ) 
    {
        has_right = has_right_child ( current_index, size );
        has_left = has_left_child ( current_index, size );

        if ( has_left )
        {   
            left_index = left_child ( current_index );
            if ( has_right ) 
            {
                right_index = right_child ( current_index );
                max_index = max ( heap->array, left_index, right_index );
                if ( heap->array [ max_index ] >= heap->array [ current_index ] )
                {
                    swap ( &heap->array [ current_index], &heap->array [ max_index ] );
                    current_index = max_index;
                } 
            } else
            {
                max_index = max ( heap->array, current_index, left_index );
                if ( heap->array [ max_index ] > heap->array [ current_index ] ) 
                {
                    swap ( &heap->array [ max_index], &heap->array [ current_index ] );
                    break;
                } else
                {
                    break;
                }
            }
        } else
        {
            break;
        }

    }

    return 1;
}

void Destroy(BinaryHeap *heap)
{
    free(heap->array);
    free(heap);
}
