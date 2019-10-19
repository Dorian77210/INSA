#include <stdio.h>
#include <stdlib.h>

#define MIN_LIMIT 100
#define MAX_LIMIT 999

int scan_int(int* x) {
    int result;
    result = scanf("%d", x);

    if(result == 0 || *x < MIN_LIMIT || *x > MAX_LIMIT) return 0;

    return 1;
}

int main(int argc, const char** argv) {

    return EXIT_SUCCESS;
}