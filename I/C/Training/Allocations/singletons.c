#include <stdio.h>
#include <stdlib.h>

int is_singleton(double* buffer, int length, double value) {
    int occuration = 0, i;
    for(i = 0; i < length; i++) {
        if(buffer[i] == value) occuration++;
    }

    return occuration == 1;
}

int main(int argc, const char** argv) {
    int n, i;
    double* buffer, x;
    printf("Give me a value : ");
    fflush(stdout);
    scanf("%d", &n);

    buffer = (double*)malloc(n * sizeof(double));
    if(!buffer) {
        fprintf(stderr, "Error when mallocing \n");
        return EXIT_FAILURE;
    }

    for(i = 0; i < n; i++) {
        scanf("%lf", &x);
        buffer[i] = x;
    }

    for(i = 0; i < n; i++) {
        if(is_singleton(buffer, n, buffer[i])) {
            printf("%lf ", buffer[i]);
            fflush(stdout);
        }
    }

    putchar('\n');
    free(buffer);
    return EXIT_SUCCESS;
}