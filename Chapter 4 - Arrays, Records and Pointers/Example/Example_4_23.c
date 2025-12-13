/*
Example 4.23

Matrix algebra examples: vector dot product and small matrix multiplication.
*/

#include <stdio.h>

int main(void) {
    int u[] = {1, 2, 3};
    int v[] = {4, 5, 6};
    int dot = 0;
    for (int i = 0; i < 3; ++i) dot += u[i] * v[i];
    printf("Dot(u,v) = %d\n", dot);

    int A[2][2] = {{1,2},{3,4}};
    int B[2][2] = {{5,6},{7,8}};
    int C[2][2] = {{0,0},{0,0}};
    for (int i = 0; i < 2; ++i)
        for (int j = 0; j < 2; ++j)
            for (int k = 0; k < 2; ++k)
                C[i][j] += A[i][k] * B[k][j];

    printf("C = A*B:\n");
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 2; ++j) printf("%d ", C[i][j]);
        printf("\n");
    }
    return 0;
}
