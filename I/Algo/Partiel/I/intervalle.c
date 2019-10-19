#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int inferior_bound;
    int superior_bound;
} Interval;

int can_associate ( Interval a, Interval b ) 
{
    return ( a.superior_bound >= b.inferior_bound );
}

Interval associate ( Interval a, Interval b ) 
{
    Interval c;
    c.inferior_bound = ( a.inferior_bound <= b.inferior_bound )
        ? a.inferior_bound
        : b.inferior_bound;

    c.superior_bound = ( a.superior_bound >= b.superior_bound )
        ? a.superior_bound
        : b.superior_bound;

    return c;
}

void shift ( Interval* intervals, int size, int begin )
{
    int i;
    for ( i = 0; i < size; i++ ) 
    {
        if ( i > begin ) 
        {
            intervals [ i - 1 ] = intervals [ i ];
        }
    }
}

int main(int argc, const char** argv) {
    int size, inferior_bound, superior_bound, i, has_done = 0;
    Interval* intervals;

    scanf ( "%d", &size );
    intervals = ( Interval* )malloc ( size * sizeof( Interval ) );

    for ( i = 0; i < size; i++ ) 
    {
        scanf( "%d %d", &inferior_bound, &superior_bound );
        intervals [ i ].inferior_bound = inferior_bound;
        intervals [ i ].superior_bound = superior_bound;
    }

    while ( !has_done ) 
    {
        has_done = 1;
        for ( i = 0; i < ( size - 1 ); i++ ) 
        {
            if ( can_associate ( intervals [ i ], intervals [ i + 1] ) )
            {
                has_done = 0;
                intervals [ i ] = associate ( intervals [ i ], intervals [ i + 1 ] );
                shift ( intervals, size, i + 1 );
                size--;
                break;
            }
        }
    }

    printf ( "%d\r\n", size );
    for ( i = 0; i < size; i++ ) 
    {
        printf("%d %d\r\n", intervals [ i ].inferior_bound, intervals [ i ].superior_bound );
    }

    free ( intervals );
    return EXIT_SUCCESS;
}