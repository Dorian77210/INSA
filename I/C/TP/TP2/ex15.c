#include <stdio.h>
#include <stdlib.h>

void swap(int* a, int* b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void swap2(int a, int b) {
    int tmp = a;
    a = b;
    b = tmp;
}

int main(int argc, const char** argv) {
    int a = 10, b = 20;

    printf("Avant le swap : %d %d \n", a, b);
    swap2(a, b);
    printf("Apres le swap : %d %d\n", a, b);

    return EXIT_SUCCESS;
}