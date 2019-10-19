#include <stdio.h>
#include <stdlib.h>

#define OUTPUT_FILENAME "outfile.txt"

int main(int argc, const char** argv) {
    if(argc != 2) {
        fprintf(stderr, "Usage : %s <filename> \n", *argv);
        return EXIT_FAILURE;
    }

    char value;
    FILE *infile, *outfile;
    infile = fopen(argv[1], "r");
    if(!infile) {
        fprintf(stderr, "Error when opening the file %s\n", argv[1]);
        return EXIT_FAILURE;
    }

    outfile = fopen(OUTPUT_FILENAME, "w");
    if(!outfile) {
        fclose(infile);
        fprintf(stderr, "Error when opening the file %s \n", OUTPUT_FILENAME);
        return EXIT_FAILURE;
    }

    while(!feof(infile)) {
        value = fgetc(infile);
        if(value == EOF) break;
        fputc(value, outfile); 
    }

    fclose(infile);
    fclose(outfile);

    return EXIT_SUCCESS;
}