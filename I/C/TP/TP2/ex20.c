#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, const char** argv) {
    const char* str = "<-_->";
    size_t len;
    int i;

    len = strlen(str);
    for(i = 0; i < len; i++) {
        putchar(*(str + i));
        putchar('.');
    }

    return EXIT_SUCCESS;
}