#ifndef LISTE_H
#define LISTE_H

#define MIN 111
#define MAX 999
#define ITERATIONS 10

struct node {
    unsigned short value;
    struct node* next;
};

typedef struct node node;

struct linked_list{
    node* first;
    node* last;
};

typedef struct linked_list linked_list;

void add(linked_list* list, unsigned short value);
void print(linked_list* list);
void destruct(linked_list* list);
unsigned short max(linked_list* list);
linked_list* create();
linked_list* sort(linked_list* list);

#endif