#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER_SIZE 100

typedef struct Node {
    struct Node* previous;
    int value;
} Node;

void push(Node** stack, int value) {
    Node* node;
    node = (Node*)malloc(sizeof(Node));
    if(!node) {
        fprintf(stderr, "Error when creating node \n");
        return;
    }

    node->value = value;
    node->previous = *stack;
    *stack = node;
}

int pop(Node** stack, int *res) {
    if(! (*stack) ) return 0;
    *res = (*stack)->value;
    Node *tmp = (*stack)->previous;
    free(*stack);
    *stack = tmp;
    return 1;
}

void destroy(Node** stack) {
    Node* courant, *tmp;

    for(courant = *stack; courant != NULL; courant = tmp) {
        tmp = courant->previous;
        free(courant);
    }
}

int main(int argc, const char** argv) {
    char buffer[MAX_BUFFER_SIZE];
    int value, res;
    Node* stack;

    while(strcmp(buffer, "bye") != 0) {
        fscanf(stdin, "%99s", buffer);
        if(strcmp(buffer, "push") == 0) {
            fscanf(stdin, "%d", &value);
            push(&stack, value);
        } else if(strcmp(buffer, "pop") == 0) {
            if(pop(&stack, &res)) {
                printf("%d\r\n", res);
            }
        } 
    }

    destroy(&stack);
    return EXIT_SUCCESS;
}