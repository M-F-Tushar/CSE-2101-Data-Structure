#include <stdio.h>

void heapify(int A[], int size, int root)  //This function makes sure root should be bigger than both children
{
    int largest, left, right, temp;

    largest = root;
    left = 2 * root;
    right = 2 * root + 1;

    // Find largest among root, left, right
    if (left <= size && A[left] > A[largest])
    {
        largest = left;
    }

    if (right <= size && A[right] > A[largest])
    {
        largest = right;
    }

    if (largest != root)
    {
        temp = A[root];
        A[root] = A[largest];
        A[largest] = temp;

        heapify(A, size, largest);
    }
}

void heapSort(int A[], int n)
{
    int i, temp;

    // Build max heap
    for (i = n / 2; i >= 1; i--)
    {
        heapify(A, n, i);
    }

    for (i = n; i >= 2; i--)
    {
        // Swap root with last element
        temp = A[1];
        A[1] = A[i];
        A[i] = temp;

        heapify(A, i - 1, 1);
    }
}

void printArray(int A[], int n)
{
    int i;
    for (i = 1; i <= n; i++)
    {
        printf("%d ", A[i]);
    }
    printf("\n");
}

int main()
{
    int A[] = {0, 40, 10, 30, 50, 60, 15};
    int n = 6;

    printf("Before sorting: ");
    printArray(A, n);

    heapSort(A, n);

    printf("After sorting: ");
    printArray(A, n);

    return 0;
}
