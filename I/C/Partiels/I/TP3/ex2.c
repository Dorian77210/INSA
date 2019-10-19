#include <stdio.h>
#include <stdlib.h>

#define BUFFER_SIZE 10

void calcul(int* buffer) {
    int max, min, average, i;

    min = max = buffer[0];
    average = 0x0;

    for(i = 0; i < BUFFER_SIZE; i++) {
        if(buffer[i] < min) min = buffer[i];
        if(buffer[i] > max) max = buffer[i];
        average += buffer[i];
    }

    printf("min = %d max = %d moy = %d\n", min, max, average / BUFFER_SIZE);
}

int main(int argc, const char** argv) {
    int buffer[BUFFER_SIZE], i, x;

    for(i = 0; i < BUFFER_SIZE; i++) {
        scanf("%d", &x);
        *(buffer + i) = x;
    }

    calcul(buffer);

    return EXIT_SUCCESS;
}