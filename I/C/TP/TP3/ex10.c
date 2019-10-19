#include <stdio.h>
#include <stdlib.h>

#define ADD_HEAD 1
#define PRINT_LIST 2
#define QUIT_APP 0
#define SEARCH_VALUE 3
#define ADD_END 4
#define DELETE_NODE 5
#define DUPLICATE_VALUE 6
#define IS_SORTED_CHOICE 7
#define REVERSE_CHOICE 8

struct node {
    int value;
    struct node* next;
};

typedef struct node node;


struct linked_list {
    node* first;
};

typedef struct linked_list linked_list;

void add_head(linked_list* list) {
    int value;
    node* n;

    printf("tapez un nombre : ");
    fflush(stdout);
    scanf("%d", &value);

    n = (node*)malloc(sizeof(node));
    if(!n) {
        fprintf(stderr, "Error during malloc for the new node with value %d \n", value);
        return;
    }

    n->value = value;
    n->next = list->first;
    list->first = n;
}

void add_end(linked_list* list) {
    int value;
    node* n, *current;

    printf("Entrez un nombre a ajouter a la fin de la liste : ");
    fflush(stdout);
    scanf("%d", &value);

    n = (node*)malloc(sizeof(node));
    if(!n) {
        fprintf(stderr, "Error during mallocing \n");
        return;
    }

    n->value = value;
    if(!list->first) list->first = n;
    else {
        for(current = list->first; current->next != NULL; current = current->next);
        current->next = n;
    }
}

void print_list(linked_list* list) {
    node* current;
    if(!list->first) {
        printf("La liste est vide \n");
        return;
    }

    for(current = list->first; current != NULL; current = current->next) {
        printf("%d\n", current->value);
    }
}

void destruct(linked_list* list) {
    node* current, *next;

    for(current = list->first; current != NULL; current = next) {
        next = current->next;
        free(current);
    }
}

void search(linked_list* list) {
    int value;
    node* current;
    int position = 0, was_found = 0;

    printf("Donnez n nombre a chercher : ");
    fflush(stdout);
    scanf("%d", &value);

    for(current = list->first; current != NULL; current = current->next) {
        if(current->value == value) {
            printf("%d trouvé en position %d \n", value, position);
            was_found = 1;
        }
    }

    if(!was_found) {
        printf("%d non trouve \n", value);
    }
}

void delete_node(linked_list* list) {
    node* current, *tmp, *previous;
    int value;

    printf("Donnez une valeur a supprimer : ");
    fflush(stdout);
    scanf("%d", &value);

    for(current = list->first; current != NULL;) {
        if(current == list->first) {
            if(current->value == list->first->value) {
                tmp = current;
                current = current->next;
                free(tmp);
                list->first = current;
            } else {
                current = current->next;
            }
        } else {
            if(current->value == value) {
                tmp = current->next;
                free(current->next);
                previous->next = tmp;
                current = tmp;
            } else {
                current = current->next;
            }
        }

        previous = current;
    }
}

void duplicate(linked_list* list) {
    node* current, *n, *tmp;
    int value;

    if(!list->first) {
        printf("Aucune valeur n'est disponible pour appliquer une duplication \n");
        return;
    }

    printf("Entrez une valeur a dupliquer : ");
    fflush(stdout);
    scanf("%d", &value);

    for(current = list->first; current != NULL;) {
        if(current->value == value) {
            n = (node*)malloc(sizeof(n));
            if(!n) {
                fprintf(stderr, "Error during malloc for the new node on dupicate function \n");
                return;
            }

            n->value = value;
            tmp = current->next;
            current->next = n;
            n->next = tmp;

            current = tmp;
        } else {
            current = current->next;
        }
    }
}

int is_sorted(linked_list* list) {
    node* current;

    for(current = list->first; current != NULL; current = current->next) {
        if(current->next) {
            if(current->value > current->next->value) return 0;
        }
    }

    return 1;
}

void add_head2(linked_list* list, node* n) {
    n->next = list->first;
    list->first = n;
}

linked_list* reverse(linked_list* list) {
    linked_list* other;
    node* current, *next;

    if(!list->first) return NULL;

    other = (linked_list*)malloc(sizeof(linked_list));
    if(!other) {
        fprintf(stderr, "Error during mallocing for the reverse \n");
        return list;
    }

    other->first = NULL;

    for(current = list->first; current != NULL;) {
        next = current->next;
        add_head2(other, current);
        current = next;
    }

    free(list);
    return other;
}

void add_sort(linked_list* list) {
    node* n, *current, *next;
    int value;
    if(is_sorted(list)) {
        printf("Tapez un nombre à rajouter : ");
        fflush(stdout);
        scanf("%d", &value);
        n = (node*)malloc(sizeof(node));
        if(!n) {
            fprintf(stderr, "Error when malloc for the new node on the function add_sort \n");
            return;
        }

        if(!list->first) list->first = n;
        else {
            if(list->first->value > value) {
                n->next = list->first;
                list->first = n;
            } else {
                for(current = list->first; current->next != NULL; current = current->next) {
                    next = current->next;
                    if((current->value < value) && (next->value > value)) {
                        current->next = n;
                        n->next = next;
                        return;
                    }
                }

                current->next = n;
            }
        }
    }
}

int main(int argc, const char** argv) {
    linked_list* list;
    int choice;
    int value;

    list = (linked_list*)malloc(sizeof(linked_list));
    if(!list) {
        fprintf(stderr, "Error during malloc for the linked_list \n");
        return EXIT_FAILURE;
    }

    list->first = NULL;

    while(1) {
        printf("menu : \n 1: ajouter en tete \n 2: afficher liste \n 3: Chercher une valeur \n 4: ajouter en queue \n 5 : Supprimer element \n6: Dupliquer une valeur \n 7: Triee ? \n 8: Retourner \n0: quitter \n");
        scanf("%d", &choice);
        printf("\033[H\033[2J");
        
        if(choice == QUIT_APP) {
            destruct(list);
            break;
        }
        else if(choice == ADD_HEAD) add_head(list);
        else if(choice == PRINT_LIST) print_list(list); 
        else if(choice == SEARCH_VALUE) search(list);
        else if(choice == ADD_END) add_end(list);
        else if(choice == DELETE_NODE) delete_node(list);
        else if(choice == DUPLICATE_VALUE) duplicate(list);
        else if(choice == IS_SORTED_CHOICE) printf("%d\n", is_sorted(list));
        else if(choice == REVERSE_CHOICE) list = reverse(list);
    }

    return EXIT_SUCCESS;
}