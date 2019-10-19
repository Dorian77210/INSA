#include <stdio.h>
#include <stdlib.h>

#define MAX_STUDENT 100
#define CAPACITY_MAX 5000

int main(int argc, const char** argv) {
    int matrix3IF[MAX_STUDENT][CAPACITY_MAX], matrix4IF[MAX_STUDENT][CAPACITY_MAX], if3[MAX_STUDENT], if4[MAX_STUDENT];
    int delta, i, j, x, type, bus_capacity, nbr_if3, nbr_if4, n, is_full, cpt;
    int last_if3, last_if4, max_if3, max_if4;

    scanf("%d", &bus_capacity);
    bus_capacity++;

    scanf("%d", &n);
    nbr_if3 = nbr_if4 = 1;

    if3[0] = if4[0] = 0;

    for(i = 0; i < n; i++) {
        scanf("%d %d", &x, &type);
        if(type == 3) {
            if3[nbr_if3] = x;
            nbr_if3++;
        } else {
            if4[nbr_if4] = x;
            nbr_if4++;
        }
    }

    // proceed the algo
    for(i = 0; i < nbr_if3; i++) {
        for(j = 0; j < bus_capacity; j++) {
            matrix3IF[i][j] = 0;
            delta = j - if3[i];
            if(j == 0) {
                matrix3IF[i][j] = 1;
            } else if((i - 1) >= 0 && delta >= 0 && matrix3IF[i - 1][j - if3[i]]) {
                matrix3IF[i][j] = 1;
            } else if((i - 1) >= 0 && matrix3IF[i - 1][j]) {
                matrix3IF[i][j] = 1;
            }

            // printf("%d ", matrix3IF[i][j]);
        }
        // putchar('\n');
    }

    // putchar('\n');

    // proceed the algo
    for(i = 0; i < nbr_if4; i++) {
        for(j = 0; j < bus_capacity; j++) {
            matrix4IF[i][j] = 0;
            delta = j - if4[i];
            if(j == 0) {
                matrix4IF[i][j] = 1;
            } else if((i - 1) >= 0 && delta >= 0 && matrix4IF[i - 1][j - if4[i]]) {
                matrix4IF[i][j] = 1;
            } else if((i - 1) >= 0 && matrix4IF[i - 1][j]) {
                matrix4IF[i][j] = 1;
            }

            // printf("%d ", matrix4IF[i][j]);
        }

        // putchar('\n');
    }

    if((nbr_if3 - 1) >= 0 && (bus_capacity - 1) >= 0 && (nbr_if4 - 1) >= 0) {
        last_if3 = matrix3IF[nbr_if3 - 1][bus_capacity - 1];
        last_if4 = matrix4IF[nbr_if4 - 1][bus_capacity - 1];

        if(last_if4 == 1 && last_if3 == 1) {
            printf("3 4\r\n");
        } else if(last_if4 == 1 && last_if3 == 0) {
            printf("4\r\n");
        } else if(last_if4 == 0 && last_if3 == 1) {
            printf("3\r\n");
        } else {
            cpt = bus_capacity - 1;
            is_full = 0;

            while(is_full != 1) {
                is_full = matrix3IF[nbr_if3 - 1][cpt];
                if(is_full) break;
                cpt--;
            }

            max_if3 = cpt;

            is_full = 0;
            cpt = bus_capacity - 1;

            while(is_full != 1) {
                is_full = matrix4IF[nbr_if4 - 1][cpt];
                if(is_full) break;
                cpt--;
            }

            max_if4 = cpt;

            if(max_if4 > max_if3) printf("4\r\n");
            else printf("3\r\n");
        }
    }

    return EXIT_SUCCESS;
}