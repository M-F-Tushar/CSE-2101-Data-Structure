#include <stdio.h>

int main()
{
    int A[] = {17, 12, 18, 5, 7, 10, 8};
    int n = 7;
    int key_value, i;

    for (int j = 1; j < n; j++)
    {
        key_value = A[j];
        i = j - 1;

        while (i >= 0 && A[i] > key_value)
        {
            A[i + 1] = A[i];
            i = i - 1;
        }

        A[i + 1] = key_value;
    }

    printf("Sorted Array:\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", A[i]);
    }

    return 0;
}