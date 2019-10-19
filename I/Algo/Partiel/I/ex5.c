#include <stdio.h>
#include <stdlib.h>

int main(int argc, const char** argv) {
    double x, average = 0.0, nbr = 0.0;
    int has_negative_values = 0, n, i;

    scanf("%d", &n);

    for(i = 0; i < n; i++) {
        scanf("%lf", &x);
        if(x <= 0.0) {
            if(!has_negative_values) has_negative_values = 1;
            average += x;
            nbr += 1.0;
        }
    }

    if(!has_negative_values) {
        printf("-\r\n");
    } else {
        printf("%lf\r\n", average / nbr);
    }


    return EXIT_SUCCESS;
}