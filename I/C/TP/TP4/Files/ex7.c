#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <time.h>

#define MAX_FILENAME_SIZE 64
#define MAX_LINE_SIZE 256

#define OUTFILE_PATH "discours.txts"

int main(int argc, const char** argv) {
    char filename[MAX_FILENAME_SIZE], line[MAX_LINE_SIZE];
    FILE* infile, *outfile;
    char** buffer;
    int i, j, random_index, shift;

    srand((unsigned)time(NULL));
    buffer = (char**)malloc(8 * 4 * sizeof(char*));

    if(!buffer) {
        fprintf(stderr, "Error during malloc for the buffer of strings \n");
        return EXIT_FAILURE;
    }

    for(i = 1; i <= 4; i++) {
        bzero(filename, MAX_FILENAME_SIZE);
        bzero(line, MAX_LINE_SIZE);
        snprintf(filename, MAX_FILENAME_SIZE - 1, "colonne%d.txt", i);
        infile = fopen(filename, "r");

        while(!feof(infile)) {
            if(!fgets(line, MAX_LINE_SIZE, infile)) {
                fprintf(stderr, "Error when reading the file %s \n", filename);
            }

            buffer[j] = line;
            j++;
        }

        fclose(infile);
    }

    outfile = fopen(OUTFILE_PATH, "w");
    if(!outfile) {
        fprintf(stderr, "Error when openging the file %s \n", OUTFILE_PATH);
        return EXIT_FAILURE;
    }

    for(i = 0; i < 5; i++) {
        for(i = 0; i < 4; i++) {
            shift = i * 4;
            random_index = shift + rand() % ((i + 1) * 4 - shift - 1);
            if(fputs(buffer[random_index], outfile) < 0) {
                fprintf(stderr, "Error !\n");
            } 
        }
    }

    fclose(outfile);


    return EXIT_SUCCESS;
}