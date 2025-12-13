/*
Example 4.8

Implement linear search with the sentinel technique.
*/

#include <stdio.h>

int linear_search_sentinel(int a[], int n, int key) {
    int last = a[n-1];
    a[n-1] = key; /* place sentinel */
    int i = 0;
    while (a[i] != key) i++;
    a[n-1] = last; /* restore */
    if (i < n-1 || last == key) return i;
    return -1;
}

int main(void) {
    int a[7] = {3, 8, 2, 5, 9, 4, 0};
    int n = 7;

    int key1 = 5;
    int idx1 = linear_search_sentinel(a, n, key1);
    printf("Find %d at index %d\n", key1, idx1);

    int key2 = 7;
    int idx2 = linear_search_sentinel(a, n, key2);
    printf("Find %d at index %d\n", key2, idx2);
    return 0;
}
