#include <stdio.h>

int main()
{
    int arr[5] = {10, 20, 30, 40, 50};
    int LB = 0;
    int UB = 4;
    
    int K = LB;
    
    while(K <= UB)
    {
        printf("%d\n", arr[K]);
        K = K + 1;
    }
    
    return 0;
}
