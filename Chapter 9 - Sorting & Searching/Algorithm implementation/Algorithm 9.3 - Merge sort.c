#include <stdio.h>

void Merge(int A[], int f, int m, int l)
{
    int T[100];
    int i = f, j = m + 1, k = f;

    while (i <= m && j <= l)
    {
        if (A[i] <= A[j])
        {
            T[k] = A[i];
            i = i + 1;
        }
        else
        {
            T[k] = A[j];
            j = j + 1;
        }
        k = k + 1;
    }

    while (i <= m)
    {
        T[k] = A[i];
        i = i + 1;
        k = k + 1;
    }

    while (j <= l)
    {
        T[k] = A[j];
        j = j + 1;
        k = k + 1;
    }

    for (int i = f; i <= l; i++)
    {
        A[i] = T[i];
    }
}

void merge_sort(int A[], int f, int l)
{
    if (f < l)
    {
        int m = (f + l) / 2;
        merge_sort(A, f, m);
        merge_sort(A, m + 1, l);
        Merge(A, f, m, l);
    }
}

int main()
{
    int A[] = {18, 26, 32, 6, 43, 15, 9, 1};
    int n = 8;

    merge_sort(A, 0, n - 1);

    printf("Sorted Array:\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", A[i]);
    }

    return 0;
}