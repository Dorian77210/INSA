#include <stdio.h>
#include <stdlib.h>

#define BUFFER_SIZE 32

int main(int argc, const char** argv) {
    if(argc != 2) {
        fprintf(stderr, "Uage : %s <filename> \n", *argv);
        return EXIT_SUCCESS;
    }

    FILE* infile;
    char* buffer;

    // allocation of memory for the buffer
    buffer = (char*)malloc(BUFFER_SIZE * sizeof(char));
    if(!buffer) {
        fprintf(stderr, "Error when mallocing for the buffer \n");
        return EXIT_FAILURE;
    }

    infile = fopen(argv[1], "r");
    if(!infile) {
        fprintf(stderr, "Error when opening the file %s \n", argv[1]);
        free(buffer);
        return EXIT_FAILURE;
    }

    while(1) {
        if(!fgets(buffer, BUFFER_SIZE, infile)) {
            break;
        }

        fputs(buffer, stdout);
    }

    free(buffer);
    return EXIT_SUCCESS;
}