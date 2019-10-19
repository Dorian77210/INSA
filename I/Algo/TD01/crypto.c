#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SUSAN_SIZE 5
#define RED_SIZE 4
#define DEER_SIZE 4

void print_susan(int susan[SUSAN_SIZE]) {
    int i;
    for(i = 0; i < SUSAN_SIZE; i++) {
        printf("%d", susan[i]);
    }

    printf("\r\n");
}

void print(int buffer[RED_SIZE]) {
    int i;
    for(i = 0; i < RED_SIZE; i++) {
        printf("%d", buffer[i]);
    }

    printf("    ");
    fflush(stdout);
}

int _check_validity(int susan[SUSAN_SIZE], int red[RED_SIZE]) {
    int i, j;
    if(susan[0] != susan[2]) return 0; // S != S
    if(susan[1] == susan[3]) return 0; // U == A
    if(susan[1] == susan[4]) return 0; // U == N
    if(susan[3] == susan[4]) return 0; // A == N
    if(susan[0] == susan[1]) return 0; // S == U
    if(susan[0] == susan[3]) return 0; // S == A
    if(susan[0] == susan[4]) return 0; // S == N

    for(i = 0; i < SUSAN_SIZE; i++) {
        for(j = 1; j < RED_SIZE; j++) {
            if(susan[i] == red[j]) return 0;
        }
    }

    return 1; 
}

void add_and_check(int red[RED_SIZE], int deer[DEER_SIZE], int susan[SUSAN_SIZE]) {
    memset(susan, 0, SUSAN_SIZE);
    int rest = 0, i, value, j = SUSAN_SIZE - 1;

    for(i = (DEER_SIZE - 1); i >= 0; i--) {
        value = red[i] + deer[i] + rest;
        rest = value / 10;
        value %= 10;
        susan[j] = value;
        j--;
    }

    susan[j--] = rest;
    if(_check_validity(susan, red) && susan[0] != 0) {
        print_susan(susan);
    }
}



int main(int argc, const char** argv) {
    int red[RED_SIZE], susan[SUSAN_SIZE], deer[DEER_SIZE];
    int r, e, d;

    memset(red, 0, RED_SIZE);
    memset(susan, 0, SUSAN_SIZE);
    memset(deer, 0, DEER_SIZE);

    for(r = 0; r <= 9; r++) {
        red[0] = 0;
        red[1] = deer[3] = r;
        for(e = 0; e <= 9; e++) {
            if(e != r) {
                deer[1] = deer[2] = red[2] = e;
            } else {
                continue;
            }
            
            for(d = 0; d <= 9; d++) {
                if((d != r) && (d != e)) {
                    deer[0] = red[3] = d;
                    add_and_check(red, deer, susan);
                }
            }
        }
    }

    return EXIT_SUCCESS;
}