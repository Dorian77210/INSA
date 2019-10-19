#include <stdio.h>
#include <stdlib.h>

#define TAB_SIZE 10

int main(int argc, const char** argv) {
    int tab[TAB_SIZE], *ptr, i;

    for(i = 0; i < TAB_SIZE; i++) {
        tab[i] = i + 1;
    }

    ptr = tab;

    // for(i = 0; i < TAB_SIZE; i++) {
    //     printf("%d \n", *(ptr + i));
    // }

    ptr = tab + 9;

    for(i = 9; i >= 0; i--) {
        if(i % 2 == 1) printf("%d\n", *(ptr - i));
    }

    return EXIT_SUCCESS;
}