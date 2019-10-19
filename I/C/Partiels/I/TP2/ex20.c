#include <stdio.h>
#include <stdlib.h>

int main(int argc, const char** argv) {
    if(argc != 2) {
        fprintf(stderr, "Usage : %s <word> \n", *argv);
        return EXIT_FAILURE;
    }

    int i;
    const char* string = argv[1];

    for(i = 0; string[i] != '\0'; i++) {
        putchar(*(string + i));
    }

    return EXIT_SUCCESS;
}