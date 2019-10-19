#include <stdlib.h>
#include <stdio.h>

int main(int argc, const char** argv) {
    int result, x, loop = 1;

    result = scanf("%d", &x);
    printf("Resultat de la fontion scanf : %d\n", result);

    while(loop) {
        result = scanf("%d", &x);
        if(result == 0 || x < 100 || x > 999) {
            printf("Tapez une valeur comprise entre 100 et 999 \n");
        } else {
            loop = 0;
        }
    }

    return EXIT_SUCCESS;
}