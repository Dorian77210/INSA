#include <stdio.h>
#include <stdlib.h>

int main(int argc, const char** argv) {
    double x = 13.12, *ptr_d;
    ptr_d = &x;

    printf("%p %p \n", x, ptr_d);
    printf("%lf %lf \n", x, *ptr_d);

    return EXIT_SUCCESS;
}