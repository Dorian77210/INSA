#include <stdio.h>
#include <stdlib.h>

int main(int argc, const char** argv) {
    if(argc != 2) {
        fprintf(stderr, "Usage : %s <filename> \n", *argv);
        return EXIT_FAILURE;
    }

    char value;
    FILE* file;

    file = fopen(argv[1], "r");
    if(!file) {
        fprintf(stderr, "Error when opening the file %s\n", argv[2]);
        return EXIT_FAILURE;
    }

    while(!feof(file)) {
        value = fgetc(file);
        if(value == EOF) break;
        fputc(value, stdout);
    }

    fclose(file);
    return EXIT_SUCCESS;
}