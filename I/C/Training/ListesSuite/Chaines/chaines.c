#include <stdio.h>
#include <stdlib.h>

#include "chaines.h"

str* array_to_string(const char* buffer) {
    str* s;
    int i;

    s = (str*)malloc(sizeof(str));
    if(!s) {
        fprintf(stderr, "Error during mallocing for the new string \n");
        return NULL;
    }

    s->first = s->last = NULL;

    for(i = 0; buffer[i] != '\0'; i++) {
        add(s, buffer[i]);
    }

    return s;
}

char* str_to_array(str* s) {
    int len, i;
    char* buffer = NULL;
    node* current;

    /* retrieve the length of the current string */
    len = length(s);
    current = s->first;
    buffer = (char*)malloc(len * sizeof(char));
    if(!buffer) {
        fprintf(stderr, "Error when malloc for the new string \n");
        return NULL;
    }

    for(i = 0; i < len; i++, current = current->next) {
        buffer[i] = current->value;
    }
}

int length(str* s) {
    node* current;
    int length = 0;

    for(current = s->first; current != NULL; current = current->next, length++);

    return length; 
}

void add(str* s, char value) {
    node* n;

    n = (node*)malloc(sizeof(node));
    if(!n) {
        fprintf(stderr, "Error when mallocing for the new node \n");
        return;
    }

    n->value = value;
    n->next = NULL;

    if(!s->first && !s->last) {
        s->first = n;
        s->last = n;
    } else {
        s->last->next = n;
        s->last = n;
    }
}

void destruct(str* s) {
    node* current, *next;

    for(current = s->first; current != NULL; ) {
        next = current->next;
        free(current);
        current = next;
    }
}

void print(str* s) {
    node* current;
    for(current = s->first; current != NULL; current = current->next) {
        putchar(current->value);
    }

    putchar('\n');
}

str* linked_list_strcpy(str* s) {
    str* p;
    node* current;

    p = (str*)malloc(sizeof(str));
    if(!p) {
        fprintf(stderr, "Error during the malloc of the new string \n");
        return NULL;
    }

    for(current = s->first; current != NULL; current = current->next) {
        add(p, current->value);
    }

    return p;
}

str* linked_list_strcat(str* a, str* b) {
    str* c;
    node* current;

    c = (str*)malloc(sizeof(str));
    if(!c) {
        fprintf(stderr, "Error during mallocing for the new str \n");
        return NULL;
    }

    for(current = a->first; current != NULL; current = current->next) {
        add(c, current->value);
    }

    for(current = b->first; current != NULL; current = current->next) {
        add(c, current->value);
    }

    return c;
}

int linked_list_strcmp(str* a, str* b) {
    node* p = a->first, *q = b->first;

    for(p; p != NULL; p = p->next) {
        if(p->value > q->value) return 1;
        if(p->value < q->value) return -1;

        q = q->next;
    }

    return 0;
}