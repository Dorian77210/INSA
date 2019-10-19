#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

int main(int argc, const char** argv) {
    int buffer[MAX_SIZE], x = 0, obj, *bag, capacity, i, j, length = 0, delta;

    scanf("%d", &capacity);
    capacity++;
    bag = (int*)malloc(capacity * sizeof(int));
    if(!bag) {
        fprintf(stderr, "Error during malloc \n");
        exit(1);
    }

    while(1) {
        scanf("%d", &x);
        if(x == -1) break;
        buffer[length] = x;
        length++;
    }

    bag[0] = 1;

    for(i = 1; i < capacity; i++) {
        for(j = 0; j < length; j++) {
            obj = buffer[j];
            delta = i - obj;
            if(delta >= 0) {
                if(bag[delta]) {
                    bag[i] = 1;
                    // break;
                }
            } 
        }
    }

    printf("%d\n", bag[capacity - 1]);
    
    return EXIT_SUCCESS;
}