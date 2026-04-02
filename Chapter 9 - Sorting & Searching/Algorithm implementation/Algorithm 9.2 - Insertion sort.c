#include <stdio.h>

int main()
{
    int A[] = {17, 12, 18, 5, 7, 10, 8};
    int n = 7;
    int key_value, i;

    for (int j = 1; j < n; j++)
    {
        key_value = A[j]; // current element
        i = j - 1; // index of the last sorted element

        while (i >= 0 && A[i] > key_value) // index is valid and  left element is bigger than key
    {
            A[i + 1] = A[i];
            i = i - 1; //Move one step left to continue checking previous elements.
        }

        A[i + 1] = key_value; //After shifting all larger elements to the right, insert key_value into the empty correct place.
    }

    printf("Sorted Array:\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", A[i]);
    }

    return 0;
}
