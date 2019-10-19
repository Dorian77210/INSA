#include <stdio.h>
#include <stdlib.h>

#define OUTFILENAME "outfile.txt"
#define BUFFER_SIZE 256

int main(int argc, const char** argv) {
    if(argc != 2) {
        fprintf(stderr, "Usage : %s <filename> \n", *argv);
        return EXIT_FAILURE;
    }

    FILE* infile, *outfile;
    char buffer[BUFFER_SIZE];

    infile = fopen(argv[1], "r");

    if(!infile) {
        fprintf(stderr, "Error when opening the file %s\n", argv[1]);
        return EXIT_FAILURE;
    }

    outfile = fopen(OUTFILENAME, "w");
    if(!outfile) {
        fprintf(stderr, "Error when opening the file %s \n", OUTFILENAME);
        fclose(infile);
    }

    while(!feof(infile)) {
        if(!fgets(buffer, BUFFER_SIZE, infile)) {
            fprintf(stderr, "Erorr when reading in the file %s \n", argv[1]);
        }

        fputs(buffer, outfile);
    }

    fclose(infile);
    fclose(outfile);

    return EXIT_SUCCESS;
}