#include <stdio.h>
#include <stdlib.h>

#define OBJECTS_SIZE 100

int main(int argc, const char** argv) {
    int bag_capacity, x, *bag, i ,j, objects[OBJECTS_SIZE], object_size = 0, delta;

    scanf("%d", &bag_capacity);
    bag_capacity++;

    bag = (int*)malloc(bag_capacity * sizeof(int));
    bag[0] = 1;

    while(1) {
        scanf("%d", &x);
        if(x == -1) break;
        objects[object_size] = x;
        object_size++;
    }

    for(i = 1; i < bag_capacity; i++) {
        for(j = 0; j < object_size; j++) {
            delta = i - objects[j];
            if(delta >= 0 && bag[delta]) {
                bag[i] = 1;
            }
        }
    }

    if(bag[bag_capacity - 1]) printf("OUI\r\n");
    else printf("NON\r\n");

    return EXIT_SUCCESS;
}