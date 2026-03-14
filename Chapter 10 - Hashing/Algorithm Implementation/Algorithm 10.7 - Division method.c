#include <stdio.h>

#define m 10

int hashAddress(int key) {
    return key % m;
}

int main() {
    int keys[] = {13, 4, 12, 9, 24};
    int n = 5;

    for (int i = 0; i < n; i++)
        printf("Key: %d  ->  Hash Address: %d\n", keys[i], hashAddress(keys[i]));

    return 0;
}
