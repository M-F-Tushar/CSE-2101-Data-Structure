#include <stdio.h>

#define m 10
#define r 3

int T[m];

void insert(int key) {
    int ind = key % m;
    while (T[ind] != 0)
        ind = ind * r % m;
    T[ind] = key;
    printf("Stored %d at index %d\n", key, ind);
}

void retrieve(int key) {
    int h = key % m;
    while (T[h] != key)
        h = h * r % m;
    printf("Found %d at index %d\n", key, h);
}

void display() {
    for (int i = 0; i < m; i++)
        printf("[%d] = %d\n", i, T[i]);
}

int main() {
    insert(901);
    insert(811);
    insert(621);
    display();
    retrieve(811);
    retrieve(621);
    return 0;
}
