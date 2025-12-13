/*
Example 4.14

Compute effective indices and simulated LOC for a 3D array (MAZE example).
Assume row-major order and contiguous storage.
*/

#include <stdio.h>

int main(void) {
    int base = 2000; /* simulated base */
    int elem = sizeof(int);
    int X = 3, Y = 3, Z = 3; /* dimensions */
    int x = 2, y = 1, z = 0; /* zero-based indices */

    int offset = (x * Y * Z) + (y * Z) + z;
    int loc = base + offset * elem;

    printf("MAZE[%d][%d][%d] with dims (%d,%d,%d): offset=%d, LOC=%d\n",
           x, y, z, X, Y, Z, offset, loc);
    return 0;
}
