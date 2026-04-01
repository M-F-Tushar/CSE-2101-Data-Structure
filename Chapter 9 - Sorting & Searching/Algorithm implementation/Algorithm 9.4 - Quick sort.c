#include<stdio.h>

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int arr[], int low, int high)
{
    int pivot = arr[low];
    int p = low + 1;
    int q = high;

    while(p <= q)
    {
        while(p <= high && arr[p] <= pivot)
        {
            p++;
        }
        while(q >= low && arr[q] > pivot)
        {
            q--;
        }
        if(p < q)
        {
            swap(&arr[p], &arr[q]);
        }
    }
    swap(&arr[low], &arr[q]);
    return q;
}

void quicksort(int arr[], int low, int high)
{
    if(low < high)
    {
        int pivotIndex = partition(arr, low, high);

        quicksort(arr, low, pivotIndex - 1);

        quicksort(arr, pivotIndex + 1, high);
    }
}

void printArray(int arr[], int size) 
{
    for (int i = 0; i < size; i++) 
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() 
{

    int arr[] = {35, 50, 15, 25, 80, 20, 90, 45};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Unsorted array: \n");
    printArray(arr, n);

    quickSort(arr, 0, n - 1);

    printf("Sorted array: \n");
    printArray(arr, n);

    return 0;
}
