#include <stdio.h>
#include <stdlib.h>

void find() {
    int a, b, c, result = 0;
    for(a = 1; a <= 9; a++) {
        for(b = 0; b <= 9; b++) {
            for(c = 0; c <= 9; c++) {
                if((a + c) == 2 * b) {
                    result++;
                }
            }
        }
    }

    printf("%d\r\n", result);
}   

int main(int argc, const char** argv) {
    find();
    return EXIT_SUCCESS;
}