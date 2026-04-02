/*
Write a program which takes a Graph, G as input using Adjacency Matrix and output the
value of total number of length 2 paths in G. (60)
*/    

#include <stdio.h>

#define Max 10

int main()
{
    int N, A[Max][Max], A2[Max][Max];

    printf("Enter all vertices: ");
    scanf("%d", &N);

    printf("Enter adjacency matrix (%dx%d):\n", N, N);
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            scanf("%d", &A[i][j]);
        }
    }

    // Compute A^2
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            A2[i][j] = 0;
            for (int k = 0; k < N; k++)
            {
                A2[i][j] += A[i][k] * A[k][j];
            }
        }
    }

    printf("\nA^2 (paths of length 2 between each pair):\n");
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
            printf("%3d ", A2[i][j]);
        printf("\n");
    }

    // Sum all entries of A^2
    int total = 0;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            total += A2[i][j];

    printf("\nTotal number of length-2 paths = %d\n", total);

    return 0;
}
