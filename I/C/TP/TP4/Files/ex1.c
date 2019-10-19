#include <stdio.h>
#include <stdlib.h>

int main(int argc, const char** argv) {
    if(argc != 2) {
        fprintf(stderr, "Usage : %s <filename> \n", *argv);
        return EXIT_FAILURE;
    }

    FILE* infile;
    char data;
    size_t read_data;

    infile = fopen(argv[1], "r");
    if(!infile) {
        fprintf(stderr, "Error when opening the file %s \n", argv[1]);
        return EXIT_FAILURE;
    }    

    while(!feof(infile)) {
        read_data = fread(&data, sizeof(char), 1, infile);
        if(!read_data) break;
        fputc(data, stdout);
    }

    putchar('\n');

    fclose(infile);

    return EXIT_SUCCESS;
}