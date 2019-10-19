#include <stdio.h>
#include <stdlib.h>

#define BUFFER_SIZE 10

int main(int argc, const char** argv) {
    int buffer[BUFFER_SIZE], i, x;

    for(i = 0; i < BUFFER_SIZE; i++) {
        scanf("%d", &x);
        *(buffer + i) = x;
    }

    for(i = 0; i < BUFFER_SIZE; i++) {
        printf("%d \n", *(buffer + i));
    }

    return EXIT_FAILURE;
}