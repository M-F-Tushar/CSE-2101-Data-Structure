// Algorithm 4.2: Inserting into a Linear Array
#include <stdio.h>

int main()
{
    int arr[10] = {10, 20, 30, 40, 50};
    int N = 5;
    int K = 2;
    int ITEM = 99;
    
    int J = N - 1;
    
    while(J >= K)
    {
        arr[J + 1] = arr[J];
        J = J - 1;
    }
    
    arr[K] = ITEM;
    
    N = N + 1;
    
    printf("Updated Array:\n");
    for(int i = 0; i < N; i++)
    {
        printf("%d\n", arr[i]);
    }
    
    return 0;
}
