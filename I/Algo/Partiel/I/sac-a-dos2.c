#include <stdio.h>
#include <stdlib.h>

#define MAX_OBJECT_NUMBER 100

int main(int argc, const char** argv) {
    int** matrix, bag_capacity, objects_number, objects[MAX_OBJECT_NUMBER], delta, x, i, j;

    x = 0;
    objects_number = 1;

    objects[0] = 0;

    // read the bag capacity
    scanf("%d", &bag_capacity);
    bag_capacity++;
    // read the objects

    while(1) {
        scanf("%d", &x);
        if(x == -1) break;

        objects[objects_number] = x;
        objects_number++;
    }

    matrix = (int**)malloc(objects_number * sizeof(int*));
    if(!matrix) {
        fprintf(stderr, "Error during mallocing for the matrix \n");
        return EXIT_FAILURE;
    }

    for(i = 0; i < objects_number; i++) {
        matrix[i] = (int*)malloc(bag_capacity * sizeof(int));
    }

    // init for the capacity 0
    for(i = 0; i < objects_number; i++) {
        matrix[i][0] = 1;
    }

    // init for object of weight 0
    for(i = 1; i < bag_capacity; i++) {
        matrix[0][i] = 0;
    }

    // proceed the algo
    for(i = 1; i < objects_number; i++) {
        for(j = 1; j < bag_capacity; j++) {
            matrix[i][j] = 0;
            delta = j - objects[i];
            if((i - 1) >= 0 && delta >= 0 && matrix[i - 1][j - objects[i]]) {
                matrix[i][j] = 1;
            } else if(matrix[i - 1][j]) {
                matrix[i][j] = 1;
            }
        }
    }

    if(matrix[objects_number - 1][bag_capacity - 1] == 1) {
        printf("OUI\r\n");
    } else {
        printf("NON\r\n");
    }

    // free the matrix
    for(i = 0; i < objects_number; i++) {
        free(matrix[i]);
    }

    free(matrix);

    return EXIT_SUCCESS;
}