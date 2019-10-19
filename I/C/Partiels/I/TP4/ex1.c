#include <stdio.h>
#include <stdlib.h>

#define OUTFILENAME "outfile"

int main(int argc, const char** argv) {
    if(argc != 2) {
        fprintf(stderr, "Usage : %s <filename> \n", *argv);
        return EXIT_FAILURE;
    }

    FILE* infile;
    unsigned char value;

    infile = fopen(argv[1], "r");
    if(!infile) {
        fprintf(stderr, "Error when opening the file %s \n", argv[1]);
        return EXIT_FAILURE;
    }

    while(!feof(infile)) {
        value = (unsigned char)fgetc(infile);
        putchar(value);
    }

    fclose(infile);

    return EXIT_SUCCESS;
}