#include <stdio.h>
#include <stdlib.h>

int len(const char* s) {
    int i = 0, l = 0;
    for(i = 0; s[i] != '\0'; i++) l++;
    return l;   
}

int tp_strcmp(const char* s1, const char* s2) {
    int i;
    int l1 = len(s1), l2 = len(s2);

    printf("%d %d\n", l1, l2);

    for(i = 0; s1[i] != '\0'; i++) {
        if(s1[i] > s2[i]) return 1;
        if(s1[i] < s2[i]) return -1;
    }

    if(l1 == l2) return 0;
    if(l1 > l2) return 1;
    if(l2 > l1) return -1;
}

int main(int argc, const char** argv) {
    if(argc != 3) {
        fprintf(stderr, "Usage : %s <str1> <str2> \n", *argv);
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}