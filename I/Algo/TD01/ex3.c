#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 1000

int is_palindrome(int* buffer, int length) {
    int i, x, y, middle = length / 2;
    if(length & 0x1) middle++;

    for(i = 0; i < middle; i++) {
        x = buffer[i];
        y = buffer[length - 1 - i];

        if(x != y) return 0;
    }

    return 1;
}

int main(int argc, const char** argv) {
    int buffer[MAX_SIZE], x = 0,length = 0;

    while((x != -1) && (length < MAX_SIZE)) {
        scanf("%d", &x);
        length++;
    }

    printf("%d\r\n", is_palindrome(buffer, length));

    return EXIT_SUCCESS;
}