#include <stdio.h>
#include <stdlib.h>

int f(int n) {
    return (n % 2 == 0) ? (n / 2) : (3 * n + 1);
}

void a(int n) {
    while(n != 0) {
        printf("%d\r\n", n);
        if(n == 1) break;
        n = f(n);
    }
}

int main(int argc, const char** argv) {
    int value;
    scanf("%d", &value);
    a(value);
    return EXIT_SUCCESS;
}