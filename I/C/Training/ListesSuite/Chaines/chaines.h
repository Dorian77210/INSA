#ifndef CHAINES_H
#define CHAINES_H

struct node {
    char value;
    struct node* next;
};
typedef struct node node;

struct str {
    struct node* first;
    struct node* last;
};
typedef struct str str;


str* array_to_string(const char* buffer);
str* linked_list_strcpy(str* s);
char* str_to_array(str* s);
void add(str* s, char value);
int length(str* s);
void destruct(str* s);
void print(str* s);
str* linked_list_strcat(str* a, str* b);
int linked_list_strcmp(str* a, str* b);

#endif