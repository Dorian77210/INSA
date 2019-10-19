#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void test ( char* str ) 
{
    char s [] = "toto";
    str = s;
}

int main ( int argc, const char** argv ) 
{
    char str [] = "titi";
    printf ( "%s\n", str );
    test ( str );
    printf( "%s\n", str );

    return EXIT_SUCCESS;
}