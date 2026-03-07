#include <stdio.h>

#define m 10

int T[m];

void insert(int key) {
    int index = key % m;
    while (T[index] != 0)
        index = index + 1;
    T[index] = key;
    printf("Stored %d at index %d\n", key, index);
}

void retrieve(int key) {
    int h = key % m;
    while (T[h] != key)
        h = h + 1;
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
