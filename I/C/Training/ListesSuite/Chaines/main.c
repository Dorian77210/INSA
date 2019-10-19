#include <stdio.h>
#include <stdlib.h>

#include "chaines.h"

int main(int argc, const char** argv) {
    if(argc != 2) {
        fprintf(stderr, "Usage : %s <str> \n", *argv);
        return EXIT_FAILURE;
    }

    str* s = array_to_string(argv[1]), *p, *q;
    p = linked_list_strcpy(s);
    q = linked_list_strcat(s, p);

    print(q);

    destruct(s);

    return EXIT_SUCCESS;
}