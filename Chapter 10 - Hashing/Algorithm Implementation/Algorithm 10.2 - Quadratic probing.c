#include <stdio.h>

#define m 10

int T[m];

void insert(int key) {
    int y0 = key % m;
    int index = y0;
    int k = 1;
    while (T[index] != 0) {
        index = (y0 + k * k) % m;
        k++;
    }
    T[index] = key;
    printf("Stored %d at index %d\n", key, index);
}

void retrieve(int key) {
    int y0 = key % m;
    int h = y0;
    int k = 1;
    while (T[h] != key) {
        h = (y0 + k * k) % m;
        k++;
    }
    printf("Found %d at index %d\n", key, h);
}

void display() {
    for (int i = 0; i < m; i++)
        printf("[%d] = %d\n", i, T[i]);
}

int main() {
    insert(13);
    insert(4);
    insert(12);
    insert(9);
    insert(24);
    display();
    retrieve(24);
    retrieve(13);
    return 0;
}
