#include <stdio.h>

#define m 7

int T[m];

void insert(int key) {
    int ind = key % m;
    int k = 1;
    int index = ind;
    if (T[ind] != 0) {
        int d = key % (m - 2) + 1;
        while (T[index] != 0) {
            index = (ind + d * k) % m;
            k++;
        }
    }
    T[index] = key;
    printf("Stored %d at index %d\n", key, index);
}

void retrieve(int key) {
    int y = key % m;
    int h = y;
    int k = 1;
    if (T[h] != key) {
        int d = key % (m - 2) + 1;
        while (T[h] != key) {
            h = (y + d * k) % m;
            k++;
        }
    }
    printf("Found %d at index %d\n", key, h);
}

void display() {
    for (int i = 0; i < m; i++)
        printf("[%d] = %d\n", i, T[i]);
}

int main() {
    insert(211);
    insert(232);
    insert(624);
    display();
    retrieve(232);
    retrieve(624);
    return 0;
}
