#include <stdio.h>
#include <stdlib.h>

int average(int *buffer, int begin, int size) {
    int result = 0, i;
    for(i = begin; i < size; i++) {
        result += buffer[i];
    }

    return result / (size - begin);
}

int main(int argc, const char** argv) {
    int *buffer, n, x, size, i, left = 0, av1, av2;
    double av_final;

    scanf("%d", &size);
    scanf("%d", &n);

    left = size;

    buffer = (int*)malloc(n * sizeof(int));
    for(i = 0; i < n; i++) {
        scanf("%d", &x);
        buffer[i] = x;
        left -= x;
    }

    av1 = average(buffer, 0, n);
    av2 = average(buffer, n - 3, n);


    av_final = (double)(av1 + av2) / 2.0;

    printf("%d\r\n", (int)(left / av_final));

    free(buffer);
    return EXIT_SUCCESS;
}