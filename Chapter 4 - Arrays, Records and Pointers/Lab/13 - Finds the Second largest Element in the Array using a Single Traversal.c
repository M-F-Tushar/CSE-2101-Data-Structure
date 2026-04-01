#include <stdio.h>

int main()
{
    int arr[] = {10, 20, 5, 8, 25, 15};
    int n = 6;

    int largest, second;

    // Step 1: Initialize using first two elements
    if (arr[0] > arr[1])
    {
        largest = arr[0];
        second = arr[1];
    }
    else
    {
        largest = arr[1];
        second = arr[0];
    }

    // Step 2: Traverse remaining elements
    for (int i = 2; i < n; i++)
    {
        if (arr[i] > largest)
        {
            second = largest;
            largest = arr[i];
        }
        else if (arr[i] > second && arr[i] != largest)
        {
            second = arr[i];
        }
    }

    printf("Second largest = %d\n", second);

    return 0;
}
