#include <stdio.h>
#include <stdlib.h>

int average(int* buffer, int length);
int interest(int* buffer, int length);

int average(int* buffer, int length) {
    int sum = 0, i;
    for(i = 0; i < length; i++) {
        sum += buffer[i];
    }

    return sum / length;
}

int interest(int* buffer, int length) {
    int interest = 0, m, i, av, x;
    m = average(buffer, length);

    for(i = 0; i < length; i++) {
        x = buffer[i];
        if((x > 0) && (x >= m)) {
            interest++;
        }
    }

    return interest;
}

int main(int argc, const char** argv) {
    int* buffer = NULL, n, x, i;
    scanf("%d", &n);
    buffer = (int*)malloc(n * sizeof(int));
    if(!buffer) {
        fprintf(stderr, "Error when malloc the tab\r\n");
        return EXIT_FAILURE;
    }

    for(i = 0; i < n; i++) {
        scanf("%d", &x);
        buffer[i] = x;
    }

    printf("%d\r\n", interest(buffer, n));
    
    free(buffer);
    return EXIT_SUCCESS;
}