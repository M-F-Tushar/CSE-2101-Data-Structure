#include <stdio.h>

int hashAddress(int key, int partSize) {
    int sum = 0;
    int divisor = 1;

    for (int i = 0; i < partSize; i++)
        divisor *= 10;

    while (key > 0) {
        sum += key % divisor;
        key /= divisor;
    }

    return sum;
}

int main() {
    int key = 324112;
    int partSize = 2;

    printf("Key        : %d\n", key);
    printf("Part Size  : %d digits\n", partSize);
    printf("Hash Address: %d\n", hashAddress(key, partSize));

    return 0;
}
