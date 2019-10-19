#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* inverse(const char* str) {
    char* s;
    int i, length;

    length = strlen(str);
    s = (char*)malloc((length + 1) * sizeof(char));
    if(!s) {
        fprintf(stderr, "Error during mallocing for the string \n");
        return NULL;
    }

    for(i = 0; i < length; i++) {
        s[i] = str[length - i - 1];
    }

    s[length] = '\0';
    return s;
}

int main(int argc, const char** argv) {
    int i;
    char* buffer;

    for(i = 1; i < argc; i++) {
        buffer = inverse(argv[i]);
        if(strcmp(buffer, argv[i]) == 0) {
            printf("%s est un palindrome \n");
        } else {
            printf("%s n'est pas un palindrome \n");
        }
    }
    
    return EXIT_SUCCESS;
}