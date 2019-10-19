#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    int allocated; /* current allcoation of array */
    int filled;    /* number of items present in the binheap */
    int *array;    /* array of values */
} BinaryHeap;

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
int parent(int index);
int right_child(int index);
int left_child(int index);
int has_left_child(int index, int size);
int has_right_child(int index, int size);
void swap(int* a, int* b);

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
    heap = (BinaryHeap *)malloc(sizeof(BinaryHeap));
    heap->allocated = size;
    heap->filled = 0x0;
    heap->array = (int*)malloc(heap->allocated * sizeof(int));

    return heap;
}

void InsertValue(BinaryHeap *heap, int value)
{
    int parent_index, current_index;
    if(heap->filled == heap->allocated) {
        heap->allocated *= 2;
        heap->array = (int*)realloc(heap->array, heap->allocated * sizeof(int));
    }

    heap->array[heap->filled] = value;
    
    parent_index = parent(heap->filled);
    current_index = heap->filled;

    while(heap->array[current_index] > heap->array[parent_index] && current_index > 0) {
        swap(&heap->array[current_index], &heap->array[parent_index]);
        current_index = parent_index;
        parent_index = parent(current_index);
    }

    heap->filled++;
}

int parent(int index) {
    return (index - 1) / 2;
}

int left_child(int index) {
    return (2 * index) + 1;
}

int right_child(int index) {
    return (2 * index) + 2;
}

void swap(int* a, int* b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

int has_right_child(int index, int size) {
    int tmp = right_child(index);
    return tmp <= size;
}

int has_left_child(int index, int size) {
    int tmp = left_child(index);
    return tmp <= size;
}

int max(int* array, int first_index, int second_index) {
    return array[first_index] >= array[second_index] 
        ? first_index
        : second_index;
}

int ExtractMax(BinaryHeap *heap, int *res)
{
    if(heap->filled == 0) return 0;
    *res = heap->array[0];
    int max_index, current_index, left_index, right_index, has_right, has_left;  

    heap->filled--;
    heap->array[0] = heap->array[heap->filled]; // last element to the top of heap

    current_index = 0;

    while(1) {
        has_right = has_right_child(current_index, heap->filled);
        has_left = has_left_child(current_index, heap->filled);

        if(!has_right && !has_left) break;

        if(has_left) {
            left_index = left_child(current_index);
            if(has_right) {
                right_index = right_child(current_index);
                max_index = max(heap->array, left_index, right_index);
                if(heap->array[max_index] >= heap->array[current_index]) {
                    swap(&heap->array[max_index], &heap->array[current_index]);
                    current_index = max_index;
                }
            } else {
                left_index = left_child(current_index);
                max_index = max(heap->array, heap->array[current_index], heap->array[left_index]);
                if(heap->array[max_index] > heap->array[current_index]) {
                    current_index = max_index;
                    break;
                } else {
                    break;
                }
            }
        } else {
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
