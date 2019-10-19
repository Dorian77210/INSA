#include <stdio.h>
#include <stdlib.h>

typedef struct {
    float real;
    float imaginary;
} Complexe;

void affiche(Complexe z) {
    if(z.imaginary > 0) {
        printf("%f + %f*i\n", z.real, z.imaginary);
    } else {
        printf("%f %f*i\n", z.real, z.imaginary);
    }
}

Complexe add(Complexe a, Complexe b) {
    Complexe z;
    z.imaginary = a.imaginary + b.imaginary;
    z.real = a.real + b.real;

    return z;
}

Complexe mul(Complexe a, Complexe b) {
    Complexe z;
    z.real = a.real * b.real;
    z.imaginary = a.imaginary * b.imaginary;

    return z;
}


int main(int argc, const char** argv) {
    Complexe z;
    float x, y;

    scanf("%f %f", &x, &y);
    z.real = x;
    z.imaginary = y;

    affiche(z);

    return EXIT_SUCCESS;
}