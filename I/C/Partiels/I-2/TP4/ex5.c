#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <strings.h>

#define BASE_PATH "colonnes/"
#define FILENAME_MAX_SIZE 64
#define MAX_BUFFER_SIZE 256

int main(int argc, const char** argv) {
    unsigned int i, j;
    char path[FILENAME_MAX_SIZE], line[MAX_BUFFER_SIZE], **buffer;
    FILE *infile;

    buffer = (char**)malloc(8 * sizeof(char*));

    for(i = 1; i <= 4; i++) {
        bzero(path, FILENAME_MAX_SIZE);
        snprintf(path, FILENAME_MAX_SIZE - 1, "%scolonne%u.txt", BASE_PATH, i);
        infile = fopen(path, "r");
        if(!infile) {
            fprintf(stderr, "Error when opening the file %s \n", path);
            continue;
        }   

        j = 0;
        while(!feof(infile)) {
            if(!fgets(line, MAX_BUFFER_SIZE, infile)) {
                fprintf(stderr, "Error when reading in the file %s\n", path);
            }

            buffer[j] = line;
            j++;
        }

        unsigned int random = rand() % 9;
        srand((unsigned)time(NULL));

        printf("%u\n", random);
        fputs(buffer[random], stdout);
        putchar('\n');
        fclose(infile);
    }

    free(buffer);

    return EXIT_SUCCESS;
}