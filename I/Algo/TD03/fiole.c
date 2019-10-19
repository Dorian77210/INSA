#include <stdio.h>
#include <stdlib.h>

#define TYPE_1 1
#define TYPE_2 2

struct Fiole {
    int type;
    int value;
    int red;
    struct Fiole* right;
    struct Fiole* left;
};

typedef struct Fiole Fiole;

Fiole* combinate(Fiole root, int value, int type);
int other_type(int type);

Fiole* init(int value, int type) {
    Fiole* fiole = NULL;
    fiole = (Fiole*)malloc(sizeof(Fiole));

    fiole->value = value;
    fiole->type = type;
    fiole->red = 0;
    fiole->right = fiole->left = NULL;

    return fiole;
}

int min(int value, Fiole b, int* type) {
    int m = b.value <= value ? b.value : value;
    *type = b.value <= value ? other_type(b.type): b.type;

    return m;
}

void free_tree(Fiole* root) {
    if(root->left == NULL && root->right == NULL) {
        free(root);
    } else {
        free_tree(root->left);
        free_tree(root->right);
    }

}

int other_type(int type) {
    return type == 1 ? 2 : 1;
}

Fiole* copy_of(Fiole* f) {
    Fiole* p = (Fiole*)malloc(sizeof(Fiole));
    p->type = f->type;
    p->value = f->value;
    p->red = f->red;

    return p;
}

void add(Fiole* root, int value, int type) {
    if(root->left == NULL && root->right == NULL) {
        Fiole* right = copy_of(root);
        root->right = right;
        root->left = combinate(*root, value, type);
    } else {
        add(root->left, value, type);
        add(root->right, value, type);
    }
}

Fiole* combinate(Fiole root, int value, int type) {
    Fiole* fiole = (Fiole*)malloc(sizeof(Fiole));
    if(root.type == type) {
        fiole->type = type;
        fiole->value = root.value + value;
        fiole->red = root.red;
    } else {
        int type;
        int m = min(value, root, &type);
        fiole->red = root.red + (2 * m);
        fiole->value = (value + root.value) - m;
        fiole->type = type;
    }
    
    fiole->right = fiole->left = NULL;


    return fiole;
}

void max(Fiole* fiole, int capacity, int* m) {
    if(fiole->red > *m && fiole->red <= capacity) *m = fiole->red;

    if(fiole->left != NULL && fiole->right != NULL) {
        max(fiole->left, capacity, m);
        max(fiole->right, capacity, m);
    }
}

int main(int argc, const char** argv) {
    int capacity, size, i, type, value, max_tree = 0xFFFFFFFF;
    Fiole* root = NULL;

    scanf("%d", &capacity);
    scanf("%d", &size);

    for(i = 0; i < size; i++) {



        scanf("%d %d", &value, &type);
        if(i == 0) root = init(value, type);
        else add(root, value, type);
    }

    // to delere
    max(root, capacity, &max_tree);
    printf("%d\r\n", max_tree);

    free_tree(root);

    return EXIT_SUCCESS;
}