#include <stdio.h>

int main() 
{
    int arr[10] = {10, 20, 30, 40, 50};
    int n = 5;
    int pos = 2;     
    int item = 88;

    for (int i = n; i > pos+1; i--)
      {
        arr[i] = arr[i-1];
      }

    arr[pos+1] = item;
    n++;

    printf("After Insert AFTER position %d:\n", pos);
    for (int i = 0; i < n; i++)
      {
        printf("%d ", arr[i]);
      }
}
