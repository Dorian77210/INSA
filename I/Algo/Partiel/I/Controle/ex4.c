#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

typedef struct {
    int green;
    int red;
    int is_filled;
} Bag;

int length(Bag bag) {
    return bag.green + bag.red;
}

Bag associate(Bag bag, int type) {
    Bag b;
    b.green = bag.green;
    b.red = bag.red;

    if(type == 1) {
        b.green++;
    } else {
        b.red++;
    }

    return b;
}

int main(int argc, const char** argv) {
    int C, n, x, type, i, delta, j, has_add;
    int  red_size = 0, green_size = 0;
    int result = 0;
    Bag** bag;
    scanf("%d", &C);
    C++;

    scanf("%d", &n);

    bag = (Bag**)malloc(n * sizeof(Bag*));
    for(i = 0; i < n; i++) {
        bag[i] = (Bag*)malloc(C * sizeof(Bag));
    }

    for(i = 0; i < n; i++) {
        scanf("%d %d", &type, &x);
        if(type == 1) {
            green[green_size] = x;
            green_size++;
        } else {
            red[red_size] = x;
            red_size++;
        }
    }

    // nint for weight 0
    for(i = 0; i < n; i++) {
        bag[i][0].is_filled = 1;
        bag[i][0].green = bag[i][0].red = 0;
    }

    for(j = 1; j < C; j++) {
        bag[0][j].red = bag[0][j].green = bag[0][j].is_filled = 0;
    }

    for(i = 0; i < red_size; i++) {
        for(j = 1; j < C; j++) {
            bag[i][j].is_filled = 0;
            delta = j - red[i];
            if(delta >= 0 && bag[i - 1][j].is_filled) {
                bag[i][j].is_filled = 1;
                bag[i][j].green = bag[i - 1][j].green;
                bag[i][j].red = bag[i - 1][j].red + 1;
            } else if(delta >= 0 && x >= 0){
                if(bag[i-1][j - red[i]].is_filled) {
                    bag[i][j].is_filled = 1;
                    bag[i][j].green = bag[i - 1][j].green;
                    bag[i][j].red = bag[i - 1][j].red + 1;
                }
            }
        }
    }


    for(i = 0; i < red_size; i++) {
        for(j = 1; j < C; j++) {
            bag[i][j].is_filled = 0;
            delta = j - red[i];
            has_add = 0;
            if(delta >= 0 && bag[i - 1][red_size + j].is_filled) {
                if(!bag[i][red_size + j].is_filled) {
                    bag[i][red_size + j].is_filled = 1;
                    if(!has_add) {
                        result++;
                        has_add = 1;   
                    }
                }
                
            } else if(delta >= 0 && x >= 0){
                if(!bag[i][red_size + j].is_filled) {
                    bag[i][red_size + j].is_filled = 1;
                    if(!has_add) {
                        result++;
                        has_add = 1;   
                    }
                }
            }
        }
    }

    if(bag[C - 1][n - 1].is_filled) {
        printf("%d\r\n", result);
    } else {
        printf("-1\r\n");
    }

    return EXIT_SUCCESS;
}