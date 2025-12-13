/*
Example 4.13

Illustrate a 3D array layout and element access.
*/

#include <stdio.h>

int main(void) {
    int A[2][2][3] = {
        { {1,2,3}, {4,5,6} },
        { {7,8,9}, {10,11,12} }
    };

    printf("3D array A[2][2][3] elements:\n");
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 2; ++j) {
            printf("Slice (%d,%d): ", i, j);
            for (int k = 0; k < 3; ++k) printf("%d ", A[i][j][k]);
            printf("\n");
        }
    }

    printf("Access A[1][0][2] = %d\n", A[1][0][2]);
    return 0;
}
