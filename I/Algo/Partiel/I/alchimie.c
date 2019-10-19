#include <stdio.h>
#include <stdlib.h>

int max(int *buffer, int size) {
    int i, m;

    for(i = 0; i < size; i++) {
        if(buffer[i]) m = i;
    }

    return m;
}

int main(int argc, const char** argv) {
    int S, V, *buffer, i, end = 0, op;

    scanf("%d", &V);
    V++;
    buffer = (int*)malloc(V * sizeof(int));
    scanf("%d", &S);

    buffer[S] = 1;

    while ( !end ) 
    {
        end = 1;
        for(i = 0; i < V; i++) {
            if(buffer[i]) {
                op = i * 2;
                if(op <= (V - 1)) {
                    if(!buffer[op]) {
                        end = 0;
                        buffer[op] = 1;
                    }
                }

                op = i * 3;
                if(op <= (V - 1)) {
                    if(!buffer[op]) {
                        end = 0;
                        buffer[op] = 1;
                    }
                }

                op = i / 5;
                if(!buffer[op]) {
                    end = 0;
                    buffer[op] = 1;
                }
            }
        }
    }

    printf("%d\r\n", max(buffer, V));

    return EXIT_SUCCESS;
}
