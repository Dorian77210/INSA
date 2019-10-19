#include <stdio.h>
#include <stdlib.h>

#define BUFFER_SIZE 10

int main(int argc, const char** argv) {
    int buffer[BUFFER_SIZE], i, *ptr, delta;
    for(i = 0; i < BUFFER_SIZE; i++) {
        buffer[i] = i + 1;
    }

    ptr = &buffer[9];

    for(i = 9; i > 0; i--) {
        delta = BUFFER_SIZE - i;
        if(delta % 2 == 1) printf("%d \n", *(ptr - delta));
    }

    return EXIT_SUCCESS;
}