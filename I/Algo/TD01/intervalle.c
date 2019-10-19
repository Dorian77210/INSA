#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int inferior_bound;
    int superior_bound;
} interval;


int can_associate(interval a, interval b) {
    return (a.superior_bound > b.inferior_bound) || (a.superior_bound == b.inferior_bound);
}

interval associate(interval a, interval b) {
    interval c;
    c.inferior_bound = 
        (a.inferior_bound >= b.inferior_bound) ? b.inferior_bound : a.inferior_bound;
    
    c.superior_bound = 
        (a.superior_bound >= b.superior_bound) ? a.superior_bound : b.superior_bound;

    return c;
}

void shift_left(interval* intervals, int length, int begin) {
    int i;
    for(i = 0; i < length; i++) {
        if(i > begin) {
            intervals[i - 1] = intervals[i]; 
        }
    }

}

int main(int argc, const char** argv) {
    interval* intervals = NULL, inter;
    int inferior_bound, superior_bound, n, i, has_done = 0;

    scanf("%d", &n);
    intervals = (interval*)malloc(n * sizeof(interval));
    if(!intervals) {
        fprintf(stderr, "Error during malloc \n");
        exit(1);
    }

    for(i = 0; i < n; i++) {
        scanf("%d %d", &inferior_bound, &superior_bound);
        inter.inferior_bound = inferior_bound;
        inter.superior_bound = superior_bound;
        intervals[i] = inter;
    }

    while(1) {
        has_done = 0;
        for(i = 0; i < (n - 1); i++) {
            if(can_associate(intervals[i], intervals[i + 1])) {
                has_done = 0;
                inter = associate(intervals[i], intervals[i + 1]);
                intervals[i] = inter;
                shift_left(intervals, n, i + 1);
                n--;
                break;
            } else has_done = 1;
        }

        if(has_done) break;
    }

    printf("%d\r\n", n);
    for(i = 0; i < n; i++) {
        printf("%d %d\r\n", intervals[i].inferior_bound, intervals[i].superior_bound);
    }

    return EXIT_SUCCESS;
}