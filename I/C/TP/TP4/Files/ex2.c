#include <stdio.h>
#include <stdlib.h>

int main(int argc, const char** argv) {
    if(argc != 3) {
        fprintf(stderr, "Usage : %s <infile> <outfile> \n", *argv);
        return EXIT_FAILURE;
    }

    FILE* infile, *outfile;
    char data;
    size_t read_data, written_data;

    infile = fopen(argv[1], "r");
    if(!infile) {
        fprintf(stderr, "Error when opening the file %s \n", argv[1]);
        return EXIT_FAILURE;
    }    

    outfile = fopen(argv[2], "w");
    if(!outfile) {
        fprintf(stderr, "Error when opening the file %s \n", argv[2]);
        fclose(infile);
        return EXIT_FAILURE;
    }

    while(!feof(infile)) {
        read_data = fread(&data, sizeof(char), 1, infile);
        if(!read_data) break;
        fputc(data, stdout);
        written_data = fwrite(&data, 1, 1, outfile);
        if(written_data != 1) {
            fprintf(stderr, "Error when writing data in the outfile %s \n", argv[2]);
        }
    }

    putchar('\n');

    fclose(infile);
    fclose(outfile);

    return EXIT_SUCCESS;
}