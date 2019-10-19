#include <stdio.h>
#include <stdlib.h>

int f(int n);
int an(int n, int i);

int f(int n) {
    return (n & 0x1) ? (3 * n) + 1 : n / 2;
}

int an(int n, int i) {
    int result;
    if(!i) {
        result = n;
        printf("%d\r\n", result);
        return n;
    }
    
    return f(an(n, i--));
}   

int main(int argc, const char** argv) {
    int n;
    scanf("%d", &n);

    printf("%d\r\n", an(n, n));

    return EXIT_SUCCESS;
}