#include <stdio.h>
#include <stdlib.h>

#define COIN_SIZE 5

typedef struct {
    unsigned int buffer[5];
} Wallet;

Wallet increments(Wallet w, int index) {
    Wallet wallet;
    int i;

    for(i = 0; i < COIN_SIZE; i++) {
        wallet.buffer[i] = w.buffer[i];
    }

    wallet.buffer[index]++;

    return wallet;
}

unsigned int wallet_length(Wallet wallet) {
    int i;
    unsigned int length = 0;
    for(i = 0; i<  COIN_SIZE; i++) {
        length += wallet.buffer[i];
    }

    return length;
}

int main(int argc, const char** argv) {
    int capacity, i, current_length, min_length, j, delta, wallet_index, index;
    Wallet* wallets, current_wallet; 
    // constants
    unsigned int MAX_UNSIGNED_INT_VALUE = 0x0FFFFFFF;
    int COINS[COIN_SIZE] = {50, 20, 10, 5, 1};


    scanf("%d", &capacity);
    capacity++;

    wallets = (Wallet*)malloc(capacity * sizeof(Wallet));

    // init the wallet for 0 value
    for(i = 0; i < 5; i++) {
        wallets[0].buffer[i] = 0x0;
    }


    for(i = 1; i < capacity; i++) {
        min_length = MAX_UNSIGNED_INT_VALUE;
        for(j = 0; j < COIN_SIZE; j++) {
            delta = i - COINS[j];
            if(delta >= 0) {
                current_length = wallet_length(wallets[delta]);
                if(current_length < min_length) {
                    min_length = current_length;
                    index = j;
                    wallet_index = delta;
                }
            }
        }

        wallets[i] = increments(wallets[wallet_index], index); 
    }

    current_wallet = wallets[capacity - 1];
    for(i = 0; i < COIN_SIZE; i++) {
        printf("%d\r\n", current_wallet.buffer[i]);
    }

    free(wallets);
    return EXIT_SUCCESS;
}