#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int is_correct_solution(int x, int y, int n, int p) {
    return (int)(pow(x, n) + pow(y, n)) == p;
}

int main(int argc, const char** argv) {
    int a, b, x, y, max, has_solution = 0;
    scanf("%d", &a);
    scanf("%d", &b);

    max = (a < b) ? b : a;
    max = (int)pow(max, 1.0 / 3.0);

    for(x = 0; x < max; x++) {
        for(y = 0; y < max; y++) {
            if(is_correct_solution(x, y, 2, a) && is_correct_solution(x, y, 3, b)) {
                if(!has_solution) has_solution = 1;
                printf("%d %d\r\n", x, y);
            }
        }
    }

    if(!has_solution) {
        printf("-\r\n");
    }

    return EXIT_SUCCESS;
}