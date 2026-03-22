// Deleting from a Linear Array
#include <stdio.h>
int main()
{
    int LA[10] = {10, 20, 30, 40, 50};
    int N = 5;//Number of elements
    int K = 3;// Position to delete
    int ITEM;//Store deleted value

    ITEM = LA[K];

    for(int J = K - 1; J < N - 1; J++)
    {
        LA[J] = LA[J + 1];
    }
    N--;

    printf("After Deletion: ");
    for(int i = 0; i < N; i++)
    {
        printf("%d ", LA[i]);
    }
}
