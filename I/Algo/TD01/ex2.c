#include <stdio.h>
#include <stdlib.h>

int main(int argc, const char** argv) {
    double average = 0.0, x;
    int n, i, negative_values = 0;

    scanf("%d", &n);
    for(i = 0; i < n; i++) {
        scanf("%lf", &x);
        if(x <= 0.0) {
            negative_values++;
            average += x;
        }
    }

    if(!negative_values) {
        printf("-\r\n");
    } else {
        printf("%f\r\n", average / negative_values);
    }

    return EXIT_SUCCESS;
}