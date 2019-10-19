#include <stdio.h>
#include <stdlib.h>

#include "liste.h"

int main(int argc, const char** argv) {
    linked_list* list = create();
    int perm;
    if(!list) {
        exit(1);
    }

    print(list);
    printf("choisissez une rotation : ");
    fflush(stdout);
    scanf("%d", &perm);
    rotation(list, perm);
    print(list);

    destruct(list);

    return EXIT_SUCCESS;
}