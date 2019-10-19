#include <stdlib.h>
#include <stdio.h>

#define INITIAL_SIZE 10

void calcul(int* buffer, int length) {
    int i, max = buffer[0], min = buffer[0], average = 0;

    for(i = 0; i < length; i++) {
        average += buffer[i];
        if(max < buffer[i]) max = buffer[i];
        if(min > buffer[i]) min = buffer[i];
    }

    average /= length;
    printf("%d %d %d\n", min, max, average);
}

int main(int argc, const char** argv) {
    int* buffer, k = 0, n = INITIAL_SIZE, x, loop = 1, *tmp;

    buffer = (int*)malloc(n * sizeof(int));
    if(!buffer) {
        fprintf(stderr, "Error during mallocing \n");
        return EXIT_FAILURE;
    }

    while(1) {
        loop = scanf("%d", &x);
        if(!loop) break; 

        if(k == n) {
            n *= 2;
            buffer = (int*)realloc(buffer, n);
            if(!buffer) {
                fprintf(stderr, "Error when reallocing \n");
                return EXIT_FAILURE;
            }
        }

        buffer[k] = x;
        k++;
    }

    calcul(buffer, k);

    free(buffer);
    return EXIT_SUCCESS;
}