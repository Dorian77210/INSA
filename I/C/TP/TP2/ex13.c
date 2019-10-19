#include <stdio.h>
#include <stdlib.h>

int main(int argc, const char** argv) {
    double matrix[10][2];
    int i, j;

    for(i = 0; i < 10; i++) {
        for(j = 0; j < 2; j++) {
            printf("%p  ", &matrix[i][j]);
        }
    }

    /* memoire alignée */

    return EXIT_SUCCESS;
}