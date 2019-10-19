#include <stdio.h>
#include <stdlib.h>

#define ADD_HEAD 1
#define PRINT_LIST 2
#define SEARCH 3
#define DELETE 4
#define DUPLICATE 5
#define REVERSE 6
#define ADD_PLACE 7

#define QUIT 0

struct Node
{
    struct Node *next;
    int value;
};

typedef struct Node Node;

void add_head(Node **list)
{
    int value;
    Node *node;

    printf("Tapez un nombre : ");
    fflush(stdout);

    scanf("%d", &value);

    node = (Node *)malloc(sizeof(Node));
    if (!node)
    {
        fprintf(stderr, "Error when mallocing for the Node \n");
        return;
    }

    node->value = value;
    node->next = *list;

    *list = node;
}

void add_head2(Node** list, Node* node) {
    node->next = *list;
    *list = node;   
}

void print_list(Node **list)
{
    Node *current_node;

    for (current_node = *list; current_node != NULL; current_node = current_node->next)
    {
        printf("%d \n", current_node->value);
    }
}

void search(Node **list)
{
    Node *current_node;
    int i, value;

    i = 0;
    printf("Tapez une valeur a rechercher : ");
    fflush(stdout);
    scanf("%d", &value);

    for (current_node = *list; current_node != NULL; current_node = current_node->next)
    {
        if (current_node->value == value)
        {
            printf("%d trouvé à la position %d \n", value, i);
            return;
        }
        i++;
    }

    printf("Pas trouvé \n");
}

void add_sorted(Node** list) {
    if(! (*list)) return;
    int value;
    Node* current, *node;

    printf("Tapez une valeur : ");
    fflush(stdout);
    scanf("%d", &value);

    node = (Node*)malloc(sizeof(Node));
    node->value = value;

    for(current = *list; current != NULL; current = current->next) {
        
    }
}

void duplicate(Node** list) {
    Node* current, *tmp, *node;
    int value;

    if(! (*list)) return;

    printf("Tapez un nombre : ");
    fflush(stdout);
    scanf("%d", &value);

    for(current = *list; current != NULL; ) {
        if(current->value == value) {
            tmp = current->next;
            node = (Node*)malloc(sizeof(Node));
            if(!node) {
                fprintf(stderr, "Error during mallocing for the new node \n");
                return;
            }

            node->value = value;
            current->next = node;
            node->next = tmp;
            current = tmp;
        } else {
            current = current->next;
        }
    }
}

Node* reverse(Node** list) {
    Node* list_bis, *current, *tmp;
    if(! (*list)) return NULL;

    for(current = *list; current != NULL; current = tmp) {
        tmp = current->next;
        add_head2(&list_bis, current);
    }

    return list_bis;
}

void delete (Node **list)
{
    Node *node, *tmp;
    int value;

    if (!(*list))
        return;

    printf("Tapez un nombre a supprimer : ");
    fflush(stdout);
    scanf("%d", &value);

    for (node = *list; node != NULL;)
    {
        if (node == *list && node->value == value)
        {
            tmp = node;
            node = tmp->next;
            free(tmp);
            *list = node;
        }
        else
        {
            if (node->next && node->next->value == value)
            {
                tmp = node->next->next;
                free(node->next);
                node->next = tmp;
                node = tmp;
            }
            else
            {
                node = node->next;
            }
        }
    }
}

void destroy(Node **list)
{
    Node *node, *futur;

    for (node = *list; node != node;)
    {
        futur = node->next;
        free(node);
        node = futur;
    }
}

int main(int argc, const char **argv)
{
    Node *list = NULL;
    int choice;

    while (1)
    {
        printf("Menu : \n");
        printf("1 : Ajouter en tete \n");
        printf("2 : Afficher la liste \n");
        printf("3 : Rechercher dans la liste \n");
        printf("4 : Supprimer elements \n");
        printf("5 : Dupliquer element \n");
        printf("6 : Inverser \n");
        printf("7 : Ajouter de maniere triee \n");

        printf("0 : Quitter \n");

        scanf("%d", &choice);
        if (choice == QUIT)
            break;
        else if (choice == ADD_HEAD)
            add_head(&list);
        else if (choice == PRINT_LIST)
            print_list(&list);
        else if (choice == SEARCH)
            search(&list);
        else if(choice == DELETE)
            delete(&list);
        else if(choice == DUPLICATE)
            duplicate(&list);
        else if(choice == REVERSE) 
            list = reverse(&list);
        else if(choice == ADD_PLACE)
            add_sorted(&list);

    }

    destroy(&list);
    return EXIT_SUCCESS;
}