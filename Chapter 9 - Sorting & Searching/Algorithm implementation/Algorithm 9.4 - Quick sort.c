#include <stdio.h>

int makepart(int A[], int first, int last)
{
    int part_value = A[first];
    int i = first;
    int j = last;
    int temp;

    do
    {
        do
        {
            i = i + 1;
        } while (i < last && A[i] <= part_value);

        do
        {
            j = j - 1;
        } while (A[j] > part_value);

        if (i < j)
        {
            temp = A[i];
            A[i] = A[j];
            A[j] = temp;
        }

    } while (i < j);

    A[first] = A[j];
    A[j] = part_value;

    return j;
}

void Quick_sort(int A[], int f, int l)
{
    if (f < l)
    {
        int j = makepart(A, f, l + 1);
        Quick_sort(A, f, j - 1);
        Quick_sort(A, j + 1, l);
    }
}

int main()
{
    int A[] = {25, 57, 48, 37, 12, 92, 86, 33};
    int n = 8;

    Quick_sort(A, 0, n - 1);

    printf("Sorted Array:\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", A[i]);
    }

    return 0;
}