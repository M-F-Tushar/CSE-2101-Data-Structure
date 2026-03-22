#include <stdio.h>

void heapify(int arr[], int size, int root)
{
    int largest = root;
    int left    = 2 * root;
    int right   = 2 * root + 1;

    if (left <= size && arr[left] > arr[largest])
    {
        largest = left;
    }

    if (right <= size && arr[right] > arr[largest])
    {
        largest = right;
    }

    if (largest != root)
    {
        // Swap
        int temp      = arr[root];
        arr[root]     = arr[largest];
        arr[largest]  = temp;

        heapify(arr, size, largest);
    }
}

void heapsort(int arr[], int n)
{
    for (int i = n / 2; i >= 1; i--)
    {
        heapify(arr, n, i);
    }

    for (int i = n; i >= 2; i--)
    {
        int temp  = arr[1];
        arr[1]    = arr[i];
        arr[i]    = temp;

        heapify(arr, i - 1, 1);
    }
}

void printArray(int arr[], int n)
{
    for (int i = 1; i <= n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main()
{
    int arr[] = {0, 4, 10, 3, 5, 1};  
    int n = 5;

    printf("Before Heapsort: ");
    printArray(arr, n);

    heapsort(arr, n);

    printf("After  Heapsort: ");
    printArray(arr, n);

    return 0;
}
