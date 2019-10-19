#include <stdio.h>
#include <stdlib.h>

void print_double(double* buffer, int length, int i) {
    if(i < length) {
        if(i == (length - 1)) {
            printf("%lf ", buffer[i]);
        } else {
            printf("%lf, ", buffer[i]);
        }
        
        i++;
        print_double(buffer, length, i);
    }
}

int main(int argc, const char** argv) {
    if(argc  == 1) {
        fprintf(stderr, "Usage : %s <n1> <n2> ... \n", *argv);
    }

    double* buffer, x;
    int i;

    buffer = (double*)malloc((argc - 1) * sizeof(double));
    if(!buffer) {
        fprintf(stderr, "Error when mallocing for the double buffer \n");
        return EXIT_FAILURE;
    }

    for(i = 1; i < argc; i++) {
        x = strtod(argv[i], NULL);
        buffer[i - 1] = x; 
    }

    print_double(buffer, (argc - 1), 0x0);
    free(buffer);

    return EXIT_SUCCESS;
}