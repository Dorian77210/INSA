#include <assert.h>
#include <ctype.h>
#include <errno.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <unistd.h>

typedef struct {
    int sexe; // 1=M, 2=F
    char prenom[25];
    int annee_naissance; // 1900..2018
    int nombre;
} tuple;

int main(int argc, char **argv)
{
    printf("Hello, prenoms\n");

    return 0;
}
