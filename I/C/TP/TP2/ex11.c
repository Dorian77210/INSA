#include <stdio.h>
#include <stdlib.h>

#define BUFFER_SIZE 10

int main(int argc, const char** argv) {
    int buffer[BUFFER_SIZE], *ptr, i;

    for(i = 0; i < BUFFER_SIZE; i++) {
        buffer[i] = i + 1;
    }

    ptr = buffer;
    for(i = 0; i < (BUFFER_SIZE + 1); i++) {
        printf("%d \n", *(ptr + i));
    }

    /* affichage une case en trop, affichage d'une valeur qui n'est pas initialisée */

    return EXIT_SUCCESS;
}