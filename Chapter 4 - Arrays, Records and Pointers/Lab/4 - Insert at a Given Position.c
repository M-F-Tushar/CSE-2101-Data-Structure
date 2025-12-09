#include <stdio.h>

int main() 
{
    int arr[10] = {10, 20, 30, 40};
    int n = 4;
    int pos = 2;  
    int item = 99;

    for (int i = n; i > pos; i--)
      {
        arr[i] = arr[i-1];
      }

    arr[pos] = item;
    n++;

    printf("After Insert at Position %d:\n", pos);
    for (int i = 0; i < n; i++)
      {
        printf("%d ", arr[i]);
      }
}
