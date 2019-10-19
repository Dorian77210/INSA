#include <time.h>
#include <stdio.h>
#include <stdlib.h>

#include "liste.h"

linked_list* create() {
    int i;
    unsigned short value;
    linked_list* list = NULL;
    srand((unsigned int)time(NULL));

    list = (linked_list*)malloc(sizeof(linked_list));
    if(!list) {
        fprintf(stderr, "Error during malloc for the linked list\n");
        return NULL;
    }

    list->first = NULL;
    list->last = NULL;

    for(i = 0; i < ITERATIONS; i++) {
        value = (unsigned short)(MIN + rand() % (MAX - MIN + 1));
        add(list, value);
    }

    return list;
}

void add(linked_list* list, unsigned short value) {
    node* n = (node*)malloc(sizeof(node)), *next;
    if(!n) {
        fprintf(stderr, "Error during malloc for the node \n");
        return;
    }

    n->value = value;
    n->next = NULL;

    if(!list->first && !list->last) {
        list->first = n;
        list->last = n;
    } else {
        list->last->next = n;
        list->last = n;
    }
}

void destruct(linked_list* list) {
    node* current;
    node* next;
    for(current = list->first; current != NULL; current = next) {
        next = current->next;
        free(current);
    }
}

void print(linked_list* list) {
    node* current;
    for(current = list->first; current != NULL; current = current->next) {
        printf("%hu \n", current->value);
    }
}

unsigned short max(linked_list* list) {
    unsigned short max;
    node* current;
    max = list->first->value;

    for(current = list->first->next; current != NULL; current = current->next) {
        if(max < current->value) {
            max = current->value;
        }
    }

    return max;
}