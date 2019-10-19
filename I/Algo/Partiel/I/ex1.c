#include <stdio.h>
#include <stdlib.h>

int main(int argc, const char** argv) {
    int x, result, i;
    result = 0x0;

    for(i = 0; i < 3; i++) {
        scanf("%d", &x);
        result += x;
    }

    printf("%d\r\n", result);

    return EXIT_SUCCESS;
}