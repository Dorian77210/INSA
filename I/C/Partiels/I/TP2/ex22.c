#include <stdio.h>
#include <stdlib.h>

int strcmp2(const char* s1, const char* s2) {
    char* s1bis = (char*)s1;
    char* s2bis = (char*)s2;

    while((*s1bis != '\0') && (*s2bis != '\0') && (*s2bis == *s1bis)) {
        s1bis++;
        s2bis++;
    }

    if(*s1bis < *s2bis) return -1;
    if(*s1bis > *s2bis) return 1;

    return 0;
}

int main(int argc, const char** argv) {

    
    return EXIT_SUCCESS;
}