#include <stdio.h>
#include <stdlib.h>

#define BUFFER_SIZE 10

int main(int argc, const char** argv) {
    int public_data[BUFFER_SIZE], private_data[BUFFER_SIZE], i, *p;
    for(i = 0; i < BUFFER_SIZE; i++) {
        public_data[i] = i + 1;
        private_data[i] = 100 + i + 1;
    }

    p = private_data;
    printf("%d \n", p[14]);

    /* memoire alignée */

    return EXIT_SUCCESS;
}