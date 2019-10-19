#include <stdio.h>
#include <stdlib.h>

int main(int argc, const char** argv) {
    const char* str = "<-_->";
    int i;

    for(i = 0; str[i] != '\0'; i++) {
        putchar(*(str + i));
        putchar('.');
    }


    return EXIT_SUCCESS;
}