#include <stdio.h>

int main() {
    int arr[10] = {10, 20, 30, 40, 50};
    int n = 5;
    int pos = 3;     
    int item = 99;

    for (int i = n; i > pos; i--)
      {
        arr[i] = arr[i-1];
      }

    arr[pos] = item;
    n++;

    printf("After Insert BEFORE position %d:\n", pos);
    for (int i = 0; i < n; i++)
      {
        printf("%d ", arr[i]);
      }
}
