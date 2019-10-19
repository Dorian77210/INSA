#include <stdio.h>
#include <stdlib.h>

int main(int argc, const char** argv) {
    int i;
    printf("Number of params ; %d\n", argc);
    for(i = 0; i < argc; i++) {
        printf("%s \n", *(argv + i));
    }

    return EXIT_SUCCESS;
}