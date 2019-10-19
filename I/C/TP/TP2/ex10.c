#include <stdio.h>
#include <stdlib.h>

#define BUFFER_SIZE 10

int main(int argc, const char** argv) {
    double buffer[BUFFER_SIZE], x, *p;
    int i;
    void* q;

    for(i = 0; i < BUFFER_SIZE; i++) {
        x = (i + 1) * 1.1;
        buffer[i] = x;
    }

    p = buffer;
    for(i = 0; i < BUFFER_SIZE; i++) {
        printf("%lf \n", *(p + i));
    }

    putchar('\n');

    q = buffer;
    for(i = 0; i < BUFFER_SIZE; i++) {
        printf("%lf\n", *(((double*)q) + i));
    }
    return EXIT_SUCCESS;
}