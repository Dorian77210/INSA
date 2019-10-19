#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define UNDEFINED -1

int reduce(int x, int* buffer) {
    int ops = 0;
    while(x != 0) {
        if(buffer[x] != UNDEFINED) {
            ops += buffer[x];
            break;
        }

        if(x & 0x3) {
            x /= 3;
        } else if(x & 0x2) {
            x /= 2;
        } else {
            x--;
        }

        ops++;
    }

    return ops;
}

int main(int argc, const char** argv) {
    int* buffer, n, i;
    scanf("%d", &n);
    n++;

    buffer = (int*)malloc(n * sizeof(int));
    if(!buffer) {
        fprintf(stderr, "Error during malloc \n");
        exit(1);
    }

    for(i = 0; i < n; i++) {
        buffer[i] = UNDEFINED;
    }

    for(i = 0; i < n; i++) {
        buffer[i] = reduce(i, buffer);
    }

    printf("%d\n", buffer[n - 1]);

    free(buffer);
    return EXIT_SUCCESS;
}