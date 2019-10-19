#include <stdio.h>
#include <stdlib.h>

int main(int argc, const char** argv) {
    int min, max, current_min, current_max, i, n, *buffer = NULL, x;
    scanf("%d", &n);

    buffer = (int*)malloc(n * sizeof(int));
    if(!buffer) {
        fprintf(stderr, "Error during malloc \n");
        return EXIT_FAILURE;
    }

    for(i = 0; i < n; i++) {
        scanf("%d", &x);
        buffer[i] = x;
    }

    min = max = current_max = current_min = buffer[0];
    for(i = 1; i < n; i++) {
        x = buffer[i];
        if(x > max) {
            current_max = max;
            max = x;
        } else if(x < min) {
            current_min = min;
            min = x;
        }
    }

    printf("%d\r\n", (current_max - current_min));    

    return EXIT_SUCCESS;
}