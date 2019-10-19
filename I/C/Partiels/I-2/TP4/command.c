#include <stdio.h>
#include <stdlib.h>

int is_numeric ( const char *str ) 
{
    int i;
    char value;
    for ( i = 0; str [ i ] != '\0'; i++ ) 
    {
        value = *( str + i );
        if ( value < 48 || value > 57 ) return 0;
    }

    return 1;
}

int main ( int argc, const char** argv ) 
{
    if ( argc != 3 ) 
    {
        fprintf ( stderr, "Usage : %s <n1> <n2> \n", *argv );
        return EXIT_FAILURE;
    }

    int x, y;
    if ( !is_numeric ( argv [1 ] ) || !is_numeric ( argv [ 2 ] ) )
    {
        putchar ( '0' );
    } else
    {
        x = (int)strtol ( argv [ 1 ], NULL, 0 );
        y = (int)strtol ( argv [ 2 ], NULL, 0 );
        printf ( "%d\n", x * y );
    }

    
    return EXIT_SUCCESS;
}