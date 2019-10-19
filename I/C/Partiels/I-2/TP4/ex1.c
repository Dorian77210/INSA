#include <stdio.h>
#include <stdlib.h>

int main(int argc, const char** argv) {
    if(argc != 2) {
        fprintf(stderr, "Usage : %s <filename> \n", *argv);
        return EXIT_FAILURE;
    }
    
    FILE* infile;
    char value;
    
    // open the file
    infile = fopen(argv[1], "r");
    if(!infile) {
        fprintf(stderr, "Error when opening the file %s \n", argv[1]);
        return EXIT_FAILURE;
    }

    while(!feof(infile)) {
        value = fgetc(infile);
        if(value == EOF) break;
        fputc(value, stdout);
    }

    fclose(infile);
    return EXIT_SUCCESS;
}