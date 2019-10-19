#include <stdlib.h>
#include <stdio.h>

#define BUFFER_SIZE 10

typedef struct {
    int min;
    int max;
    int average;
} calculation;

void calcul(int* buffer) {
    int i;
    calculation c = {buffer[0], buffer[0], 0};

    for(i = 0; i < BUFFER_SIZE; i++) {
        c.average += buffer[i];
        if(buffer[i] > c.max) c.max = buffer[i];
        if(buffer[i] < c.min) c.min = buffer[i];
    }


    c.average /= BUFFER_SIZE;
    printf("%d %d %d\n", c.min, c.max, c.average);
}

int main(int argc, const char** argv) {
    int buffer[BUFFER_SIZE], i, x;
    for(i = 0; i < BUFFER_SIZE; i++) {
        scanf("%d", &x);
        buffer[i] = x;
    }

    return EXIT_SUCCESS;
}