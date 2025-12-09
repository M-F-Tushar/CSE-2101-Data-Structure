#include <stdio.h>

int main() 
{
    int arr[10] = {10, 20, 30, 40};
    int n = 4;

    for (int i = 0; i < n-1; i++)
      {
        arr[i] = arr[i+1];
      }

    n--;

    printf("After Delete Beginning:\n");
    for (int i = 0; i < n; i++)
      {
        printf("%d ", arr[i]);
      }
}
