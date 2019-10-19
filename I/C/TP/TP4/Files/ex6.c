#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <time.h>

#define MAX_FILENAME_SIZE 64
#define MAX_LINE_SIZE 256

int main(int argc, const char** argv) {
    char filename[MAX_FILENAME_SIZE], line[MAX_LINE_SIZE];
    FILE* infile;
    char** buffer;
    int i, j, random_index;

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

        random_index = rand() % 8;
        fputs(buffer[random_index], stdout);
        putchar('\n');

        fclose(infile);
    }


    return EXIT_SUCCESS;
}