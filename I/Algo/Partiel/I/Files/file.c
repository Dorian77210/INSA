#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER_SIZE 100

typedef struct Node {
    struct Node *next;
    int value;
} Node;

void enqueue(Node **queue, int value) {
    Node* node, *courant;
    node = (Node*)malloc(sizeof(Node));
    if(!node) {
        fprintf(stderr, "Error when creating the new node\n");
        return;
    }

    node->value = value;
    node->next = NULL;

    if(! (*queue)) {
        *queue = node;
        return;
    }

    for(courant = *queue; courant->next != NULL; courant = courant->next);
    courant->next = node;
}

int dequeue(Node **queue, int *res) {
    if(! (*queue)) return 0;
    Node* tmp = (*queue)->next;
    *res = (*queue)->value;
    free(*queue);
    *queue = tmp;
    return 1;
}

void destroy(Node **queue) {
    Node *courant, *tmp;
    for(courant = *queue; courant != NULL; courant = tmp) {
        tmp = courant->next;
        free(courant);
    }
}

int main(int argc, const char** argv) {
    char buffer[MAX_BUFFER_SIZE];
    int res, value;
    Node *queue;

    while(strcmp(buffer, "bye") != 0) {
        fscanf(stdin, "%99s", buffer);
        if(strcmp(buffer, "enqueue") == 0) {
            fscanf(stdin, "%d", &value);
            enqueue(&queue, value);
        } else if(strcmp(buffer, "dequeue") == 0) {
            if(dequeue(&queue, &res)) {
                printf("%d\r\n", res);
            }
        }
    }

    destroy(&queue);
    return EXIT_SUCCESS;
}