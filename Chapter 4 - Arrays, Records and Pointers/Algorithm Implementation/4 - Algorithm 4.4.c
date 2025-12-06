//Bubble Sort
#include <stdio.h>

int main() 
{
    int A[] = {45, 12, 78, 34, 23, 56};
    int N = 6;
    int i, j, temp;

    for(int i = 0; i < N - 1; i++)
    {
        for(int j = 0; j < N - 1; j++)
        {
            if(A[j] > A[j+1])
            {
                int temp = A[j];
                A[j] = A[j+1];
                A[j+1] = temp;
            }
        }
    }
    

    for (i = 0; i < N; i++)
        printf("%d ", A[i]);
}
