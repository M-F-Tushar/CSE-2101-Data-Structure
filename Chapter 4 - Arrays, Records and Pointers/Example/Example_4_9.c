/*
Example 4.9

Implement binary search on a sorted array and show one found and one not-found case.
*/

#include <stdio.h>

int binary_search(int a[], int n, int key) {
    int lo = 0, hi = n - 1;
    while (lo <= hi) {
        int mid = lo + (hi - lo) / 2;
        if (a[mid] == key) return mid;
        else if (a[mid] < key) lo = mid + 1;
        else hi = mid - 1;
    }
    return -1;
}

int main(void) {
    int a[] = {1, 3, 4, 6, 8, 10, 12};
    int n = sizeof(a)/sizeof(a[0]);

    int k1 = 8;
    int i1 = binary_search(a, n, k1);
    printf("Find %d -> index %d\n", k1, i1);

    int k2 = 7;
    int i2 = binary_search(a, n, k2);
    printf("Find %d -> index %d\n", k2, i2);
    return 0;
}
