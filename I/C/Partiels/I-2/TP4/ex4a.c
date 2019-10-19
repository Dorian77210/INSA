#include <stdio.h>
#include <stdlib.h>

#define BUFFER_SIZE 32

int main(int argc, const char** argv) {
    if(argc != 2) {
        fprintf(stderr, "Usage : %s <filename> \n", *argv);
        return EXIT_FAILURE;
    }

    char buffer[BUFFER_SIZE];
    FILE *infile;

    infile = fopen(argv[1], "r");
    while(!feof(infile)) {
        if(!fgets(buffer, BUFFER_SIZE, infile)) {
            break;
        }

        fputs(buffer, stdout);
    }

    fclose(infile);

    return EXIT_SUCCESS;
}