#include <stdio.h>
#include <stdlib.h>

#define OUTFILENAME "outfile.txt"
#define BUFFER_SIZE 256

int main(int argc, const char** argv) {
    if(argc != 2) {
        fprintf(stderr, "Usage : %s <filename> \n", *argv);
        return EXIT_FAILURE;
    }

    FILE* infile;
    char* buffer;

    infile = fopen(argv[1], "r");
    if(!infile) {
        fprintf(stderr, "Error when opening the file %s \n", argv[1]);
        return EXIT_FAILURE;
    }

    while(!feof(infile)) {
        fgets(buffer, BUFFER_SIZE, infile);
        fputs(buffer, stdout);
    }

    fclose(infile);

    return EXIT_SUCCESS;
}