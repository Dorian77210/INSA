#include <assert.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <stdio.h>
#include <stdint.h>

int main(int argc, char* argv[])
{
    FILE *infile;
    char buffer;

    for(int i=1; i<argc ; i++)
    {
        infile = fopen(argv[i], "r");
        if (!infile)
        {
            fprintf(stderr, "Error during the opening of the file %s\n", argv[i]);
            continue;
        }

        while ((buffer = fgetc(infile)) != EOF)
        {
            putchar (buffer);
        }

        fclose (infile);
    }    

    return 0;
}
