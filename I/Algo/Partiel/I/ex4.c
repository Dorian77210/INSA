#include <stdio.h>
#include <stdlib.h>

#define MAX_ARRAY_SIZE 1000

int is_palindrome(int* buffer, int size) {
    int i, a, b;

    for(i = 0; i < size; i++) {
        a = buffer[i];
        b = buffer[size - i - 1];

        if(a != b) return 0;
    }

    return 1;
}

int main(int argc, const char** argv) {
    int size, buffer[MAX_ARRAY_SIZE], x = 0;
    size = 0;

    while(1) {
        scanf("%d", &x);
        if(x == -1) break;
        buffer[size] = x;
        size++;
    }

    printf("%d\r\n", is_palindrome(buffer, size));

    return EXIT_SUCCESS;
}