/*
Example 4.12

Compute LOC for a 2D array element in row-major order.
We simulate with a base address and element size.
*/

#include <stdio.h>

int main(void) {
    int base = 1000; /* simulated base address */
    int elem = sizeof(int);
    int rows = 3, cols = 4;
    int i = 2, j = 3; /* zero-based indices */

    int loc = base + (i * cols + j) * elem;
    printf("Row-major LOC for A[%d][%d] (rows=%d, cols=%d): %d\n",
           i, j, rows, cols, loc);
    return 0;
}
