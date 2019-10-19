#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

int main(int argc, const char** argv) {
    int objects[MAX_SIZE], x = 0, **matrix, capacity, i, j, nbr_objects = 1, delta;

    scanf("%d", &capacity);
    capacity++;
    objects[0] = 0;

    while(1) {
        scanf("%d", &x);
        if(x == -1) break;
        objects[nbr_objects] = x;
        nbr_objects++;
    }
    
    matrix = (int**)malloc(nbr_objects * sizeof(int*));
    for(i = 0; i < nbr_objects; i++) {
        matrix[i] = (int*)malloc(capacity * sizeof(int));
    }

    // init for weight 0
    for(i = 0; i < nbr_objects; i++) {
        matrix[i][0] = 1;
    }

    for(j = 1; j < capacity; j++) {
        matrix[0][j] = 0;
    }

    for(i = 1; i < nbr_objects; i++) {
        for(j = 1; j < capacity; j++) {
            matrix[i][j] = 0;
            delta = i - 1;
            x = j - objects[i];
            if(delta >= 0 && matrix[i - 1][j]) {
                matrix[i][j] = 1;
            } else if(delta >= 0 && x >= 0){
                if(matrix[i-1][j-objects[i]]) {
                    matrix[i][j]=1;
                }
            }
        }
    }

    if(matrix[nbr_objects - 1][capacity - 1] == 1) {
        printf("OUI\r\n");
    } else {
        printf("NON\r\n");
    }

    free(matrix);
    return EXIT_SUCCESS;
}