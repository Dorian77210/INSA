#include <stdio.h>
#include <stdlib.h>

void swap(int* a, int *b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

int main(int argc, const char** argv) {
    int a = 10, b = 20;
    printf("Before : %d %d\n", a, b);
    swap(&a, &b);
    printf("After : %d %d\n", a, b);

    return EXIT_SUCCESS;
}