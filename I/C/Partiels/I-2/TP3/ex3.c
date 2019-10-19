#include <stdio.h>
#include <stdlib.h>

void calcul(int *buffer, int size) {
    int i, max, average, min;
    average = 0;
    min = max = buffer[0];

    for(i = 0; i < size; i++) {
        if(buffer[i] < min) min = buffer[i];
        if(buffer[i] > max) max = buffer[i];
        average += buffer[i];
    }

    printf("N=%d min=%d max=%d moy=%d\n", size, min, max, average / size);
}

int main(int argc, const char** argv) {
    int i, *buffer, x, size;
    scanf("%d", &size);

    buffer = (int*)malloc(size * sizeof(int));
    if(!buffer) {
        fprintf(stderr, "Error during mallocing for the buffer \n");
        return EXIT_FAILURE;
    }

    for(i = 0; i < size; i++) {
        scanf("%d", &x);
        buffer[i] = x;
    }

    calcul(buffer, size);

    free(buffer);
    return EXIT_SUCCESS;
}