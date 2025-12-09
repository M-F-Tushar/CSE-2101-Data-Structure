#include <stdio.h>

int main() 
{
    int arr[10] = {10, 20, 30};
    int n = 3;
    int item = 40;

    arr[n] = item;
    n++;

    printf("After Insert at End:\n");
    for (int i = 0; i < n; i++)
      {
        printf("%d ", arr[i]);
      }
}
