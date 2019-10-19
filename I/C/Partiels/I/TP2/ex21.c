#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, const char** argv) {
    if(argc != 2) {
        fprintf(stderr, "Usage : %s <word> \n", *argv);
        return EXIT_FAILURE;
    }

    int i;
    for(i = 0; i < strlen(argv[1]); i++) {
        putchar(*(argv[1] + i));
    }

    putchar('\n');

    return EXIT_SUCCESS;
}