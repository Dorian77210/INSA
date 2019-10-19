#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int average;
    int max;
    int min;
} Calculation;

Calculation calcul(int* buffer, int size) {
    int i;
    Calculation calculation;
    calculation.min = buffer[0];
    calculation.max = buffer[0];
    calculation.average = 0;

    for(i = 0; i < size; i++) {
        calculation.average += buffer[i];
        if(calculation.min > buffer[i]) {
            calculation.min = buffer[i];
        } else if(calculation.max < buffer[i]) {
            calculation.max = buffer[i];
        }
    }

    calculation.average /= size;

    return calculation;
}

int main(int argc, const char** argv) {
    int N, *buffer, i, x;
    Calculation c;

    scanf("%d", &N);
    buffer = (int*)malloc(N * sizeof(int));
    if(!buffer) {
        fprintf(stderr, "Error during malloc for the buffer of int \n");
        return EXIT_FAILURE;
    }

    for(i = 0; i < N; i++) {
        scanf("%d", &x);
        buffer[i] = x;
    }

    c = calcul(buffer, N);
    printf("N = %d min = %d max = %d average = %d \n", N, c.min, c.max, c.average);

    free(buffer);
    return EXIT_SUCCESS;
}