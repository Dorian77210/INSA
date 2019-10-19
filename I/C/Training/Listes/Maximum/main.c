#include <stdio.h>
#include <stdlib.h>

#include "liste.h"

int main(int argc, const char** argv) {
    linked_list* list = create();
    if(!list) {
        exit(1);
    }

    print(list);
    printf("%hu\n", max(list));
    destruct(list);

    return EXIT_SUCCESS;
}