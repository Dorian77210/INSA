#include <stdio.h>
#include <stdlib.h>

int is_first(int a) {
    int i;
    for(i = 2; i < a; i++) {
        if((a % i) == 0) return 0;
    }

    return 1;
}

int main(int argc, const char** argv) {
    if(argc != 2) {
        fprintf(stderr, "Usage : %s <n> \n", *argv);
        return EXIT_FAILURE;
    }

    int x = (int)strtol(argv[1], NULL, 0);
    printf("%d \n", is_first(x));

    return EXIT_SUCCESS;
}