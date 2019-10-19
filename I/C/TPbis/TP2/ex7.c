#include <stdio.h>
#include <stdlib.h>

#define TAB_SIZE 10

int main(int argc, const char** argv) {
    int tab[TAB_SIZE], i;

    for(i = 0; i < TAB_SIZE; i++) {
        printf("%p \n", tab + i);
        // at each turn, the adress increments of sizeof(int)
    }

    return EXIT_SUCCESS;    
}