#include <stdio.h>
#include <stdlib.h>

#include "liste.h"

int main(int argc, const char** argv) {
    linked_list* list = create(), *l;
    if(!list) {
        exit(1);
    }

    print(list);
    l = sort(list);
    print(l);
    destruct(list);

    return EXIT_SUCCESS;
}