#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER_SIZE 100

typedef struct {
    int *array;
    int allocated;
    int filled;
} Stack;

Stack* init(int size) {
    Stack* stack;
    stack = (Stack*)malloc(sizeof(Stack));
    if(!stack) {
        fprintf(stderr, "Error when initializing the stack\n");
        return NULL;
    }

    stack->allocated = size;
    stack->filled = 0;
    stack->array = (int*)malloc(size * sizeof(int));
    if(!stack->array) {
        fprintf(stderr, "Error when initialing the array for the stack\n");
        free(stack);
        return NULL;
    }

    return stack;
}

void push(Stack* stack, int value) {
    if(stack->filled == stack->allocated) {
        stack->allocated *= 2;
        stack->array = (int*)realloc(stack->array, stack->allocated * sizeof(int));
    }

    stack->array[++stack->filled] = value;
}

int pop(Stack* stack, int *res) {
    if(stack->filled == 0) return 0;
    *res = stack->array[stack->filled--];
    return 1;
}

void destroy(Stack* stack) {
    free(stack->array);
    free(stack);
}

int main(int argc, const char** argv) {
    char buffer[MAX_BUFFER_SIZE];
    int value, res;
    Stack* stack = init(10);

    while(strcmp(buffer, "bye") != 0) {
        fscanf(stdin, "%99s", buffer);
        if(strcmp(buffer, "push") == 0) {
            fscanf(stdin, "%d", &value);
            push(stack, value);
        } else if(strcmp(buffer, "pop") == 0) {
            if(pop(stack, &res)) {
                printf("%d\r\n", res);
            }
        } 
    }

    destroy(stack);
    return EXIT_SUCCESS;
}