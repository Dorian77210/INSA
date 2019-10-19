#include <stdio.h>
#include <stdlib.h>

int is_present(int *buffer, int size, int value) {
    int i;

    for(i = 0; i < size; i++) {
        if(buffer[i] == value) return 1;
    }

    return 0;
}

int max(int *buffer, int size) {
    int m = buffer[0], i;

    for(i = 0; i < size; i++) {
        if(m < buffer[i]) m = buffer[i];
    }

    return m;
}

int main(int argc, const char** argv) {
    int *buffer, V, S, i, has_add = 1, size = 1, shift = 0, copy_size;
    int op;

    scanf("%d", &V);
    scanf("%d", &S);

    buffer = (int*)malloc(V * sizeof(int));
    buffer[0] = S;

    while ( has_add ) {
        if(size == V) break;

        copy_size = size;
        has_add = 0;
        for ( i = shift; i < copy_size; i++ ) {
            op = buffer[i] * 3;
            if(!is_present(buffer, size, op) && op <= V) {
                buffer[size] = op;
                if(op == V) {
                    printf("%d\r\n", op);
                    return 0;
                }
                size++;
                has_add = 1;
            }

            op = buffer[i] * 2;
            if(!is_present(buffer, size, op) && op <= V) {
                buffer[size] = op;
                if(op == V) {
                    printf("%d\r\n", op);
                    return 0;
                }
                size++;
                has_add = 1;
            }        

            op = buffer[i] / 5;
            if(op != 0 && !is_present(buffer, size, op)) {
                buffer[size] = op;
                size++;
                has_add = 1;
            }
        }

        shift = size - copy_size - 1;
    }

    printf("%d\r\n", max(buffer, size));

    free(buffer);
    return EXIT_SUCCESS;
}