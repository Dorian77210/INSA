#include <stdio.h>
#include <stdlib.h>

#define MAX_BUFFER_SIZE 100

typedef struct {
    char *array;
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
    stack->array = (char*)malloc(size * sizeof(char));
    if(!stack->array) {
        fprintf(stderr, "Error when initialing the array for the stack\n");
        free(stack);
        return NULL;
    }

    return stack;
}

void push(Stack* stack, char value) {
    if(stack->filled == stack->allocated) {
        stack->allocated *= 2;
        stack->array = (char*)realloc(stack->array, stack->allocated * sizeof(char));
    }

    stack->array[++stack->filled] = value;
}

int pop(Stack* stack, char *res) {
    if(stack->filled == 0) return 0;
    *res = stack->array[stack->filled--];
    return 1;
}

void destroy(Stack* stack) {
    free(stack->array);
    free(stack);
}

int main(int argc, const char** argv) {
    if(argc != 2) {
        fprintf(stderr, "Usage : %s <filename> \n", *argv);
        return EXIT_FAILURE;
    }

    const char begins[] = { '(', '{', '[' };
    const char ends[] = { ')', '}', ']' };
    Stack* stack;
    FILE* infile;
    char value, tmp;
    int i;

    stack = init(10);

    infile = fopen(argv[1], "r");
    if(!infile) {
        fprintf(stderr, "Error when opening the file %s \n", argv[1]);
        destroy(stack);
        return EXIT_FAILURE;
    }

    int end = 0, good = 1;

    while(!feof(infile) && !end) {
        value = fgetc(infile);
        if(value == EOF) break;

        for(i = 0; i < 3; i++) {
            if(value == begins[i]) {
                push(stack, value);
            }
            else if(value == ends[i]) {
                if(pop(stack, &tmp)) {
                    if(tmp != begins[i]) {
                        printf("Mal parenthese\n");
                        good = 0;
                        end = 1;
                        break;
                    }
                }
            }
        }
    }

    if(good) {
        printf("Bien parenthese\n");
    }   

    fclose(infile);
    destroy(stack);

    return EXIT_SUCCESS;
}