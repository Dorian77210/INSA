#include <stdio.h>
#include <stdlib.h>

#define ARRAY_SIZE 10

int main(int argc, const char** argv) {
    int array[ARRAY_SIZE], i;

    for(i = 0; i < 10; i++) {
        *(array + i) = i + 1;
    }

    for(i = 0; i < 11; i++) {
        printf("Addr = %p, value = %d \n", &array[i], array[i]);
    }

    return EXIT_SUCCESS;
}