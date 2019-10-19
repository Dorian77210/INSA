#include <stdio.h>
#include <stdlib.h>

int main(int argc, const char** argv) {
    double d = 13.12;
    printf("%.2lf %p \n", d, &d);
    return EXIT_SUCCESS;
}