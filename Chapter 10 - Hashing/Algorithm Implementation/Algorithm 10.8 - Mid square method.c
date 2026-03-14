#include <stdio.h>

int hashAddress(int key, int k) {
    long long squared = (long long)key * key;

    int totalBits = 0;
    long long temp = squared;
    while (temp > 0) {
        totalBits++;
        temp /= 2;
    }

    int skip = (totalBits - k) / 2;

    int hash = (squared >> skip) & ((1 << k) - 1);

    return hash;
}

int main() {
    int key = 89;
    int k = 3;

    printf("Key     : %d\n", key);
    printf("Squared : %lld\n", (long long)key * key);
    printf("k bits  : %d\n", k);
    printf("Hash Address: %d\n", hashAddress(key, k));

    return 0;
}
