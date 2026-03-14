#include <stdio.h>
#include <stdlib.h>

#define m 10

struct node {
    int key_value;
    struct node *next;
};

struct node *table[m];

void insert(int key) {
    int index = key % m;
    struct node *nptr = (struct node *)malloc(sizeof(struct node));
    nptr->key_value = key;
    nptr->next = NULL;
    if (table[index] == NULL) {
        table[index] = nptr;
    } else {
        struct node *tptr = table[index];
        while (tptr->next != NULL)
            tptr = tptr->next;
        tptr->next = nptr;
    }
    printf("Stored %d at index %d\n", key, index);
}

void retrieve(int key) {
    int index = key % m;
    struct node *tptr = table[index];
    while (tptr != NULL) {
        if (tptr->key_value == key) {
            printf("Found %d at index %d\n", key, index);
            return;
        }
        tptr = tptr->next;
    }
    printf("%d not found\n", key);
}

void display() {
    for (int i = 0; i < m; i++) {
        printf("[%d] -> ", i);
        struct node *tptr = table[i];
        while (tptr != NULL) {
            printf("%d -> ", tptr->key_value);
            tptr = tptr->next;
        }
        printf("NULL\n");
    }
}

int main() {
    for (int i = 0; i < m; i++)
        table[i] = NULL;
    insert(102);
    insert(402);
    insert(13);
    insert(4);
    insert(24);
    display();
    retrieve(402);
    retrieve(24);
    return 0;
}
