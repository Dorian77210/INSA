#include <stdio.h>
#include <stdlib.h>

#define ARRAY_SIZE 10

int main(int argc, const char** argv) {
    double array[ARRAY_SIZE], x = 1.1;
    int i;

    for(i = 0; i < ARRAY_SIZE; i++) {
        *(array + i) = x;
        x += 1.1;
    }

    

    return EXIT_SUCCESS;
}