/*
Example 4.7

Demonstrate bubble sort with step-by-step printouts for each pass.
*/

#include <stdio.h>

void print_array(int a[], int n) {
    for (int i = 0; i < n; ++i) printf("%d ", a[i]);
    printf("\n");
}

int main(void) {
    int a[] = {5, 1, 4, 2, 8};
    int n = sizeof(a)/sizeof(a[0]);

    printf("Original: "); print_array(a,n);

    for (int pass = 1; pass < n; ++pass) {
        int swapped = 0;
        for (int j = 0; j < n - pass; ++j) {
            if (a[j] > a[j+1]) {
                int t = a[j]; a[j] = a[j+1]; a[j+1] = t;
                swapped = 1;
            }
        }
        printf("After pass %d: ", pass); print_array(a,n);
        if (!swapped) break;
    }

    printf("Sorted:   "); print_array(a,n);
    return 0;
}
