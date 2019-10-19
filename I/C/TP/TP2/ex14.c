#include <stdio.h>
#include <stdlib.h>

#define VECTOR_SIZE 20

int main(int argc, const char** argv) {
    double vector[VECTOR_SIZE];
    int i;

    for(i = 0; i < VECTOR_SIZE; i++) {
        printf("%p  ", vector + i);
        if(i & 0x2) putchar('\n');
    }

    return EXIT_SUCCESS;
}