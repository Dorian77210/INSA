#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

#define OUTFILE "outfile.txt"

int main ( int argc, const char** argv ) 
{
    if ( argc != 2 ) 
    {
        fprintf ( stderr, "Usage : %s <filename> \n", *argv );
        return EXIT_FAILURE;
    }

    int infile, outfile;
    char value;
    ssize_t bytes;

    // open the infile and outfile
    infile = open ( argv [ 1 ], O_RDONLY );
    if ( infile == -1 )
    {
        fprintf ( stderr, "Error when opengin the file %s \n", argv [ 1 ] );
        return EXIT_FAILURE;
    }

    outfile = open ( OUTFILE, O_TRUNC | O_WRONLY | O_CREAT );
    if ( outfile == -1 ) 
    {
        fprintf ( stderr, "Error when opening the file %s \n", OUTFILE );
        close ( infile );
        return EXIT_FAILURE;
    }

    while ( 1 ) 
    {
        bytes = read ( infile, &value, 1 );
        if ( bytes == 0 ) break;
        else if ( bytes == -1 ) 
        {
            fprintf ( stderr, "Error when reading the file %s \n", argv [ 1 ] );
        }

        bytes = write ( outfile, &value, 1 );
        if ( bytes != sizeof ( char ) ) 
        {
            fprintf ( stderr, "Error when writing on the file %s \n", OUTFILE );
        }
    }

    close ( infile );
    close ( outfile );

    return EXIT_SUCCESS;
}