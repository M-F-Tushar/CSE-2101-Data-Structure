#include <stdio.h>

int main() {
    int arr[10] = {10, 20, 30, 40, 50};
    int n = 5;
    int pos = 1;      
    int del = pos + 1;

    for (int i = del; i < n-1; i++)
      {
        arr[i] = arr[i+1];
      }

    n--;

    printf("After Delete AFTER position %d:\n", pos);
    for (int i = 0; i < n; i++)
      {
        printf("%d ", arr[i]);
      }
}
