#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main ( int argc, const char** argv ) 
{
    if ( argc != 2 )
    {
        fprintf ( stderr, "Usage : %s <filename> \n", *argv );
        return EXIT_FAILURE;
    }

    int fd;
    char value;
    ssize_t size;

    fd = open ( argv [ 1 ], O_RDONLY );
    if ( fd == -1 ) 
    {
        perror ( "Error when opening the file \n" );
        return EXIT_FAILURE;
    }

    while ( 1 )
    {
        size = read ( fd, &value, 1 );
        if ( size == 0 ) break;
        if ( size == -1 ) 
        {
            fprintf ( stderr, "Error when reading the file %s \n", *argv );
        }

        fputc ( value, stdout );
    }

    close ( fd );
}