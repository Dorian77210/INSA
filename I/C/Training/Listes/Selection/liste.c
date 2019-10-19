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
    node* n = (node*)malloc(sizeof(node));
    if(!n) {
        fprintf(stderr, "Error during malloc for the node \n");
        return;
    }

    n->value = value;
        n->next = list->first;
        list->first = n;
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
        printf("%hu ", current->value);
        fflush(stdout);
    }

    putchar('\n');
}

unsigned short max(linked_list* list) {
    node* max_node = list->first, *current, *previous_node, *next_node;
    unsigned short current_value, max_value = max_node->value;
    previous_node = max_node;

    for(current = list->first; current->next != NULL; current = current->next) {
        next_node = current->next;
        if(max_value < next_node->value) {
            max_value = next_node->value;
            max_node = next_node;
            previous_node = current;
        }
    }

    if(previous_node == list->first) {
        next_node = list->first->next;
        free(list->first);
        list->first = next_node;
    } else {
        next_node = previous_node->next->next;
        free(previous_node->next);
        previous_node->next = next_node;
    }

    return max_value;
}

linked_list* sort(linked_list* list) {
    linked_list* new;
    unsigned short max_value;
    new = (linked_list*)malloc(sizeof(linked_list));
    if(!new) {
        fprintf(stderr, "Error for mallocing for the new list \n");
        return NULL;
    }

    new->first = NULL;

    while(list->first) {
        max_value = max(list);
        add(new, max_value);
    }

    return new;
}