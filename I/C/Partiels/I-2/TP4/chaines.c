#include <stdio.h>
#include <stdlib.h>

int occurences(char c, const char *str) {
    int occurence = 0, i;
    for(i = 0; str[i] != '\0'; i++) {
        if(str[i] == c) occurence++;
    }

    return occurence;
}   

int main(int argc, const char** argv) {
    if (argc != 4) {
        fprintf(stderr, "Usage : %s <n> <c> <str> \n", *argv);
        return EXIT_FAILURE;
    }

    int n, result;

    n = (int)strtol(argv[1], NULL, 0);
    result = occurences(*argv[2], argv[3]);

    result == n ? printf("1\n") : printf("0\n");

    return EXIT_SUCCESS;
}