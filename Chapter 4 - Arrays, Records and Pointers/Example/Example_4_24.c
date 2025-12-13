/*
Example 4.24

Show Strassen-like 2x2 multiplication using 7 multiplications demonstration.
(This is a demonstration; correctness shown for 2x2 case.)
*/

#include <stdio.h>

int main(void) {
    int A[2][2] = {{1,2},{3,4}};
    int B[2][2] = {{5,6},{7,8}};

    int M1 = (A[0][0] + A[1][1]) * (B[0][0] + B[1][1]);
    int M2 = (A[1][0] + A[1][1]) * B[0][0];
    int M3 = A[0][0] * (B[0][1] - B[1][1]);
    int M4 = A[1][1] * (B[1][0] - B[0][0]);
    int M5 = (A[0][0] + A[0][1]) * B[1][1];
    int M6 = (A[1][0] - A[0][0]) * (B[0][0] + B[0][1]);
    int M7 = (A[0][1] - A[1][1]) * (B[1][0] + B[1][1]);

    int C00 = M1 + M4 - M5 + M7;
    int C01 = M3 + M5;
    int C10 = M2 + M4;
    int C11 = M1 - M2 + M3 + M6;

    printf("C = A*B via 7 multiplications:\n");
    printf("%d %d\n%d %d\n", C00, C01, C10, C11);
    return 0;
}
