/*
Example 4.25

Sparse triangular matrix stored in linear array B with index mapping.
For upper triangular (1-based i<=j): L = j*(j-1)/2 + i.
For this demo we use 1-based indexing in the mapping formula.
*/

#include <stdio.h>

int index_upper(int i, int j) {
    return j*(j-1)/2 + i; /* 1-based i,j expected */
}

int main(void) {
    int n = 4;
    int size = n*(n+1)/2;
    int B[20] = {0}; /* enough space */

    /* Fill upper triangle of a 4x4 matrix with sample values A[i][j] = 10*i + j (1-based) */
    for (int i = 1; i <= n; ++i) {
        for (int j = i; j <= n; ++j) {
            int val = 10*i + j;
            int L = index_upper(i,j);
            B[L] = val;
        }
    }

    /* Access demo: read A[2][4] via B */
    int L = index_upper(2,4);
    printf("A[2][4] fetched from B[%d] = %d\n", L, B[L]);

    return 0;
}
