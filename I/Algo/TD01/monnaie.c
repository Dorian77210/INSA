#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int buffer[5];
} wallet;

unsigned length(wallet w) {
    unsigned i, result = 0;
    for(i = 0; i < 5; i++) {
        result += w.buffer[i];
    }
    return result;
}

wallet associate(wallet w, int index) {
    w.buffer[index]++;

    return w;
}

int main(int argc, const char** argv) {
    wallet* w = NULL, current_wallet;
    int n, i, j, delta, item, min, to_add;
    unsigned max_int = 0x0FFFFFFF, current_length, l;
    int items[] = {50, 20, 10, 5, 1};

    scanf("%d", &n);
    n++;
    w = (wallet*)malloc(n * sizeof(wallet));
    
    // init the first case of the wallet
    for(i = 0; i < 5; i++) {
        w[0].buffer[i] = 0x0;
    }

    for(i = 1; i < n; i++) {
        current_length = max_int;
        min = 0;
        for(j = 0; j < 5; j++) {
            item = items[j];
            delta = i - item;
            if(delta >= 0) {
                current_wallet = w[delta];
                l = length(current_wallet);
                if(l < current_length) {
                    current_length = l;
                    to_add = j;
                    min = delta;
                }
            }
        } 

       w[i] = associate(w[min], to_add); 
    }

    current_wallet = w[n - 1];
    for(i = 0; i < 5; i++) {
        printf("%d\r\n", current_wallet.buffer[i]);
    }

    free(w);

    return EXIT_SUCCESS;
}