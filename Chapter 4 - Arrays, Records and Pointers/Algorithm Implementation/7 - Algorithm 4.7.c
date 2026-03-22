#include <stdio.h>

int main()
{
    int M = 2, P = 3, N = 2;

    int A[2][3] = 
    {
        {1, 2, 3},
        {4, 5, 6}
    };
    
    int B[3][2] = 
    {
        {7, 8},
        {9, 10},
        {11, 12}
    };

    int C[2][2];

    for(int I = 0; I < M; I++)
    {
        for(int J = 0; J < N; J++)
        {
            C[I][J] = 0;

            for(int K = 0; K < P; K++)
            {
                C[I][J] += A[I][K] * B[K][J];
            }
        }
    }

    printf("Matrix Mul: \n");
    for(int i = 0; i < M; i++)
    {
        for(int j = 0; j < N; j++)
        {
            printf("%d ", C[i][j]);
        }
        printf("\n");
    }

}
