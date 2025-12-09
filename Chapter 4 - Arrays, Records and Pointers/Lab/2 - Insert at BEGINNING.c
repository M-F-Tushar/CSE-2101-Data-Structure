#include <stdio.h>

int main() 
{
    int arr[10] = {20, 30, 40, 50};
    int n = 4;
    int item = 10;

    for (int i = n; i > 0; i--)
    {
        arr[i] = arr[i-1];
    }

    arr[0] = item;
    n++;

    printf("After Insert at Beginning:\n");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
}
