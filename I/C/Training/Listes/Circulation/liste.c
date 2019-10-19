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
        add_end(list, value);
    }

    return list;
}

void add_end(linked_list* list, unsigned short value) {
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

void add_begin(linked_list* list, unsigned short value) {
    node* new;

    new = (node*)malloc(sizeof(node));
    if(!new) {
        fprintf(stderr, "Error during malloc for the new node \n");
        return;
    }

    new->value = value;
    new->next = list->first;
    list->first = new;
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

node* remove_last(linked_list* list) {
    node* current, *next, *last = list->last;
    for(current = list->first; current != NULL; current = current->next) {
        next = current->next;
        if(next && !next->next) {
            current->next = NULL;
            list->last = current;
            break;
        }
    }

    return last;
}

node* remove_first(linked_list* list) {
    node* first = list->first, *next;
    if(first->next != NULL) {
        next = first->next;
        first->next = NULL;
        list->first = next;
    }

    return first;
}

void rotation(linked_list* list, int perm) {
    int i;
    node* n;
    if(perm > 0) {
        for(i = 0; i < perm; i++) {
            n = remove_last(list);
            add_begin(list, n->value);
        }
    } else {
        for(i = perm; i < 0; i++) {
            n = remove_first(list);
            add_end(list, n->value);
        }
    }
}