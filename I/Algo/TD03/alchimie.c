#include <stdio.h>
#include <stdlib.h>

struct Node {
    int operations;
    struct Node* left;
    struct Node* down;
    struct Node* right;
};

typedef struct Node Node;

Node* init(int value) {
    Node* root = (Node*)malloc(sizeof(Node));
    root->left = root->down = root->right = NULL;
    root->operations = value;

    return root;
}

int* buffer;
int size;

int is_present(int value) {
    int i;

    for(i = 0; i < size; i++) {
        if(buffer[i] == value) return 1;
    }

    return 0;
}

void fill(Node* root, Node* node, int capacity, int* m) {
    if(node->operations > capacity || node->operations == 0 || *m == capacity) return;

    if(*m < node->operations) *m = node->operations;

    Node* right, *left, *down;
    int a, b, c;

    a = 3 * node->operations;
    b = 2 * node->operations;
    c = node->operations / 5;

    if(!is_present(a)) {
        buffer[++size] = a;
        left = (Node*)malloc(sizeof(Node));
        left->operations = a;
        left->right = left->down = left->left = NULL;
        node->left = left;
        if(*m < left->operations && left->operations <= capacity) *m = left->operations;
        
        fill(root, left, capacity, m);
    }

    if(!is_present(b)) {
        buffer[++size] = b;
        down = (Node*)malloc(sizeof(Node));
        down->operations = b;
        down->right = down->down = down->left = NULL;
        if(*m < down->operations && down->operations <= capacity) *m = down->operations;
        node->down = down;
        fill(root, down, capacity, m);
    }

    if(!is_present(c)) {
        buffer[++size] = c;
        right = (Node*)malloc(sizeof(Node));
        right->operations = c;
        right->left = right->down = right->right = NULL;
        if(*m < right->operations && right->operations <= capacity) *m = right->operations;
        node->right = right;
        fill(root, right, capacity, m);
    }
}

// void max(Node* node, int capacity, int* m) {
//     if(node->operations > *m && node->operations <= capacity) *m = node->operations;


//     if(node->left) {
//         max(node->left, capacity, m);
//     }

//     if(node->down) {
//         max(node->down, capacity, m);
//     }

//     if(node->right) {
//         max(node->right, capacity, m);
//     }
// }

int main(int argc, const char** argv) {
    int capacity, begin, m = 0xFFFFFFFF;
    Node* root;

    scanf("%d", &capacity);
    scanf("%d", &begin);

    size = 1;
    buffer = malloc(size * sizeof(int));
    buffer[0] = begin;

    root = init(begin);
    fill(root, root, capacity, &m);

    printf("%d\r\n", m);


    return EXIT_SUCCESS;
}