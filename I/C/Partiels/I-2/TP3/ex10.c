#include <stdio.h>
#include <stdlib.h>

#define DISPLAY_OPTION 1
#define QUIT_OPTION 0
#define ADD_HEAD_OPTION 2
#define SEARCH_VALUE_OPTION 3
#define ADD_QUEUE_OPTION 4

typedef struct Node {
    int value;
    struct Node *next; 
} Node;

void display_menu() {
    printf("menu : \n");
    printf("1 : Afficher la liste \n");
    printf("2 : Ajouter en tete \n");
    printf("3 : Rechercher un nombre \n");
    printf("0 : Quitter application \n");
}

void add_head(Node** list) {
    int value;
    Node* node;

    printf("Donnez une valeur a ajouter a la liste : ");
    fflush(stdout);
    scanf("%d", &value);

    // create the new node
    node = (Node*)malloc(sizeof(Node));
    if(!node) {
        fprintf(stderr, "Error when creating the new node \n");
        return;
    }

    node->value = value;
    node->next = *list;
    *list = node;
}

void display_list(Node** list) {
    if(! (*list)) {
        printf("Liste vide \n");
        return;
    }

    Node* current_node;
    for(current_node = *list; current_node != NULL; current_node = current_node->next) {
        printf("%d ", current_node->value);
    }

    putchar('\n');
}

void delete_list(Node** list) {
    Node* current, *next;

    for(current = *list; current != NULL; current = next) {
        next = current->next;
        free(current);
    }
}

void query(Node** list) {
    int i, is_found, value;
    Node* current;

    i = 0;

    printf("Donnez une valeur a rechercher : ");
    fflush(stdout);
    scanf("%d", &value);

    for(current = *list; current != NULL; current = current->next) {
        if(current->value == value) {
            if(!is_found) is_found = 1;
        }

        printf("Valeur %d trouve en position %d \n", value, i);
        i++;
    }

    if(!is_found) {
        printf("Pas trouve\n");
    }
}

void add_queue(Node** list) {
    int value;
    Node* node, *current;
}

int main(int argc, const char** argv) {
    Node* list;
    int choice;

    while(1) {
        display_menu();
        scanf("%d", &choice);
        if(choice == QUIT_OPTION) {
            break;
        }
        if(choice == ADD_HEAD_OPTION) add_head(&list);
        if(choice == DISPLAY_OPTION) display_list(&list);
        if(choice == SEARCH_VALUE_OPTION) query(&list);
    }

    return EXIT_SUCCESS;
}