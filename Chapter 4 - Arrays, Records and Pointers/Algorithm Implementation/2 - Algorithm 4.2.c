// Insert an Element into an Array
#include <stdio.h>
int main()
{
    int LA[10] = {10, 20, 30, 40, 50};
    int N = 5; // Number of elements
    int ITEM = 25; // Element to insert
    int K = 3; // Position to insert

    int J = N - 1;

    while(J >= K -1)
    {
        LA[J + 1] = LA[J];
        J--;
    }
    LA[K - 1] = ITEM;

    N++;

    printf("Array after insertion:\n");
    for(int i = 0; i < N; i++)
    {
        printf("%d ", LA[i]);

    }
    printf("\n");

}