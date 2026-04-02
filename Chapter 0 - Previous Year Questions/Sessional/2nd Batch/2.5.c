/*
Q.5. Implement the QUICK_SORT(A, LOW, HIGH) algorithm to sort an array A[ ] of n elements in ascending order using the divide-and-conquer approach. Here, LOW and HIGH represent the starting and ending indices of the array segment to be sorted. Use the PARTITION(A, LOW, HIGH) subroutine to 
select a pivot element, rearrange the elements such that all elements less than the pivot come before it and all greater elements come after, and then recursively apply QUICK_SORT to the left and right subarrays. Write the complete C/C++ implementation and test it with user-input data, displaying the array before and after sorting. Clearly highlight recursive calls in your implementation. (40)
*/
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
