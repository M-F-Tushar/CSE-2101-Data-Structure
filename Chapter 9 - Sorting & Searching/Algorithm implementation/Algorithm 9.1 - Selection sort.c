#include <stdio.h>

int main()
{
    int A[] = {12, 18, 5, 7, 10, 8, 17};
    int n = 7;
    int small_index, temp;

    for (int i = 0; i < n - 1; i++)
    {
        small_index = i;

        for (int j = i + 1; j < n; j++)
        {
            if (A[j] < A[small_index])
            {
                small_index = j;
            }
        }

        temp = A[i];
        A[i] = A[small_index];
        A[small_index] = temp;
    }

    printf("Sorted Array:\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", A[i]);
    }

    return 0;
}