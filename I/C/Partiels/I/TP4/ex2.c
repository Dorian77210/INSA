#include <stdlib.h>
#include <stdio.h>

#define OUTFILENAME "outfile.txt"

int main(int argc, const char** argv) {
    if(argc != 2) {
        fprintf(stderr, "Usage : %s <filename> \n", *argv);
        return EXIT_FAILURE;
    }

    FILE* infile, *outfile;
    int value;

    infile = fopen(argv[1], "r");
    outfile = fopen(OUTFILENAME, "w");

    if(!infile || !outfile) {
        fprintf(stderr, "Error when opening files \n");
        return EXIT_FAILURE;
    }

    while(!feof(infile)) {
        value = fgetc(infile);
        if(value == EOF) {
            break;
        }

        if(fputc(value, outfile) == EOF) {
            fprintf(stderr, "Error when writing in the file %s \n", OUTFILENAME);
        }
    }

    fclose(infile);
    fclose(outfile);

    return EXIT_SUCCESS;
}