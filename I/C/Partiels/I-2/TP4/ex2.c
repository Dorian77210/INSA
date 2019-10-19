#include <stdio.h>
#include <stdlib.h>

#define OUTFILE "outfile.txt"

int main(int argc, const char** argv) {
    if(argc != 2) {
        fprintf(stderr, "Usage : %s <filename> \n", *argv);
        return EXIT_SUCCESS;
    }

    FILE* infile, *outfile;
    char value;

    infile = fopen(argv[1], "r");
    if(!infile) {
        fprintf(stderr, "Error when opening the file %s \n", argv[1]);
        return EXIT_FAILURE;
    }

    outfile = fopen(OUTFILE, "w");
    if(!outfile) {
        fprintf(stderr, "Error when opening the file %s\n", OUTFILE);
        fclose(infile);
        return EXIT_FAILURE;
    }

    while(1) {
        value = fgetc(infile);
        if(value == EOF) break;
        fputc(value, outfile);
    }

    fclose(infile);
    fclose(outfile);

    return EXIT_SUCCESS;
}