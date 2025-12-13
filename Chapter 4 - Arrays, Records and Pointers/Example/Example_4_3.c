/*
Example 4.3

Demonstrate base-address calculation concept by simulating computed addresses
for elements in a 1D array (assuming element size in bytes).
*/

#include <stdio.h>

int main(void) {
    int base = 1000; /* pretend base address */
    int elem_size = sizeof(int); /* typically 4 */
    int A[6] = {5, 6, 7, 8, 9, 10};

    printf("Simulated addresses (base = %d, elem_size = %d):\n", base, elem_size);
    for (int i = 0; i < 6; ++i) {
        int addr = base + i * elem_size;
        printf("A[%d] at %d : %d\n", i, addr, A[i]);
    }

    return 0;
}
