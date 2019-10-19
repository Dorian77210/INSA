#include <stdio.h>
#include <stdlib.h>

#define MAX_ARRAY_SIZE 10000
#define MAX_OBJECTS 100

int main(int argc, const char** argv) {
    int i, j, *bag, capacity, items[MAX_OBJECTS], objects_size, object = 0;
    int delta;
    capacity = objects_size = 0;

    scanf("%d", &capacity);
    capacity++;

    bag = (int*)malloc(capacity * sizeof(int));

    while(1) {  
        scanf("%d", &object);
        if(object == -1) break;
        items[objects_size] = object;
        objects_size++;
    }

    bag[0] = 1;
    for(i = 1; i < capacity; i++) {
        bag[i] = 0;
        for(j = 0; j < objects_size; j++) {
            object = items[j];
            delta = i - object;
            if(delta >= 0) {
                if(bag[delta]) {
                    bag[i] = 1;
                }
            }
        }
    }

    if(bag[capacity - 1]) printf("OUI\r\n");
    else printf("NON\r\n");


    free(bag);
    return EXIT_SUCCESS;
}