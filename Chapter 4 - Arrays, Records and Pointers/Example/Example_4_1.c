/*
Example 4.1

a) Show the elements of the array LA and the index positions used to access them.
b) Demonstrate how to print an element given its index.

Answer: Simple C program that defines an array and prints indices and values.
*/

#include <stdio.h>

int main(void) {
    int LA[] = {10, 20, 30, 40, 50};
    int n = sizeof(LA) / sizeof(LA[0]);

    printf("Array contents (index : value):\n");
    for (int i = 0; i < n; ++i) {
        printf("%2d : %d\n", i, LA[i]);
    }

    /* Demonstrate accessing element by index */
    int idx = 2;
    printf("\nElement at index %d is %d\n", idx, LA[idx]);

    return 0;
}
