#include <stdio.h>

int main() {
    int arr[10] = {10, 20, 30, 40};
    int n = 4;

    n--;   

    printf("After Delete End:\n");
  
    for (int i = 0; i < n; i++)
      {
        printf("%d ", arr[i]);
      }
}
