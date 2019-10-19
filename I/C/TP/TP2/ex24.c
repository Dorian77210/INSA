#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define ASCII_TO_INT 48

int atoi2(const char* s, int base) {
    int result = 0, len, i, x, delta;
    len = strlen(s);    
    for(i = 0; i < len; i++) {
        x = s[i] - ASCII_TO_INT;
        delta = (int)pow((double)base, (double)(len - i - 1));
        result += x * delta;
    }

    return result;
}

char* itoa2(int value) {
    int max_pow, i, result, temp, delta, j;
    char* buffer;

    max_pow = (int)log10((double)value);
    buffer = (char*)malloc((max_pow + 2) * sizeof(char));
    if(!buffer) {
        fprintf(stderr, "Error during mallocing for the itoa2 \n");
        return NULL;
    }

    result = value;
    j = 0;

    for(i = max_pow; i >= 0; i--) {
        temp = (int)pow(10.0, (double)i);
        delta = result / temp;
        buffer[j] = (char)(delta + 48);
        delta = temp;
        result -= delta;
        j++;
    }

    buffer[j] = '\0';
    return buffer;
}

int main(int argc, const char** argv) {
    if(argc != 2) {
        fprintf(stderr, "Usage : %s <n> \n", *argv);
        return EXIT_FAILURE;
    }

    int x = (int)strtol(argv[1], NULL, 0);
    char* buffer = itoa2(x);
    fputs(buffer, stdout);
    putchar('\n');

    free(buffer);

    return EXIT_SUCCESS;
}