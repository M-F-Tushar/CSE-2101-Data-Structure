/*
Example 4.5

Demonstrate appending an element to the end of an array with bounds checking.
*/

#include <stdio.h>

int main(void) {
    int arr[6] = {1, 2, 3, 4, 5};
    int n = 5; /* current number of elements */
    int capacity = 6;

    int to_append = 6;
    if (n < capacity) {
        arr[n++] = to_append;
        printf("Appended %d. New array:\n", to_append);
        for (int i = 0; i < n; ++i) printf("%d ", arr[i]);
        printf("\n");
    } else {
        printf("Cannot append: array full\n");
    }

    return 0;
}
