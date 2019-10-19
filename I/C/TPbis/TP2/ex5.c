#include <stdio.h>
#include <stdlib.h>

int main(int argc, const char** argv) {
    double x, *ptr_d;
    void* generic_ptr;

    printf("%ld %ld %ld \n", sizeof(x), sizeof(ptr_d), sizeof generic_ptr);

    return EXIT_SUCCESS;
}