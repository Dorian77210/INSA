#include <stdio.h>
#include <stdlib.h>

unsigned add(unsigned a, unsigned b, short* flag) {
    unsigned result = a + b;
    unsigned min = (a < b) ? a : b;
    *flag = (result - min) == b;
    return result;
}

int main(int argc, const char** argv) {
    unsigned res, a, b;
    short flag;

    scanf("%u", &a);
    scanf("%u", &b);

    res = add(a, b, &flag); 
    if(flag) {
        printf("Tout s'est bien passé : %d\n", res);
    } else {
        printf("Aie \n");
    }

    return EXIT_SUCCESS;
}