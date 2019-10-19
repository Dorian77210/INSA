#include <stdio.h>
#include <stdlib.h>

int factorielle(int n) {
    if(n == 0 || n == 1) return 1;
    return n * factorielle(n - 1);
}

int main(int argc, const char** argv) {
    int n;
    scanf("%d", &n);
    printf("%d\r\n", factorielle(n));
    return EXIT_SUCCESS;
}