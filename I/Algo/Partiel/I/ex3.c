#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main(int argc, const char** argv) {
    int A, B, x, y, limit, res1, res2, is_found = 0x0;
    scanf("%d", &A);
    scanf("%d", &B);

    limit = (A > B) ? (int)sqrt((double)A) : (int)sqrt((double)B);

    for(x = 0; x < limit; x++) {
        for(y = 0; y < limit; y++) {
            res1 = (int)pow((double)x, 2) + (int)pow((double)y, 2);
            res2 = (int)pow((double)x, 3) + (int)pow((double)y, 3);

            if(res1 == A && res2 == B) {
                printf("%d %d\r\n", x, y);
                is_found = 1;
            }
        }
    }

    if(!is_found) {
        printf("-\r\n");
    }

    return EXIT_SUCCESS;
}