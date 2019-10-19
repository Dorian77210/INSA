#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>

#define BUFFER_SIZE 32

int main ( int argc, const char** argv ) 
{   
    if ( argc != 2 ) 
    {
        fprintf ( stderr, "Usage : %s <filename> \n", *argv );
        return EXIT_FAILURE;
    }

    int fd;
    char buffer [ BUFFER_SIZE ];
    ssize_t bytes_read;

    fd = open ( argv [ 1 ], O_RDONLY );
    if ( fd == -1 ) 
    {
        fprintf ( stderr, "Error when opening the file %s \n", argv [ 1 ] );
        return EXIT_FAILURE;
    }

    while ( 1 ) 
    {
        bytes_read = read ( fd, buffer, BUFFER_SIZE );
        if ( bytes_read == -1 || bytes_read == 0 ) break;  
        if( bytes_read != BUFFER_SIZE )
        {
            printf ( "%s", buffer ); 
            break;
        } 
        printf ( "%s", buffer );
    }

    close ( fd );

    return EXIT_SUCCESS;
}