#include <stdio.h>
#include <stdlib.h>

int global_variable;

int main(int argc, const char** argv) {
    int variable;
    printf("%p  %p\n", &global_variable, &variable);
    return EXIT_SUCCESS;
}