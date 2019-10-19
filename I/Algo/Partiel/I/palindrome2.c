#include <stdio.h>
#include <stdlib.h>

#define BUFFER_MAX_SIZE 1000

int is_palindrome ( int *buffer, int size )
{
    int i;

    for ( i = 0; i < size; i++ ) 
    {
        if ( buffer [ i ] != buffer [ size - i - 1 ] ) return 0;
    }

    return 1;
}

int main ( int argc, const char** argv )
{
    int buffer [ BUFFER_MAX_SIZE ], x, size;
    size = 0;

    while ( 1 ) 
    {
        scanf ( "%d", &x );
        if ( x == -1 ) break;
        buffer [ size ] = x;
        size++;
    }

    printf( "%d\r\n", is_palindrome ( buffer, size ) );

    return EXIT_SUCCESS;
}