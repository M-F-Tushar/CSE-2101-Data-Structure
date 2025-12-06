#include<stdio.h>
int main()
{
    int LA[7] = {0, 247, 56, 429, 135, 87, 156};
    int LB = 1;
    int UB = 6;
    int K = LB;
    int sum = 0;
    int count = 0;

    printf("Traversing array elements:\n");

    while(K <= UB)
    {
        printf("LA[%d] = %d\n", K, LA[K]);
        sum += LA[K];
        if(LA[K] > 100)
        {
            count ++;
        }
        K++;
    }
    printf("\nSum of array elements: %d\n", sum);
    printf("Count of elements greater than 100: %d\n", count);
    printf("Average of array elements: %2f\n", (float)sum / (UB - LB + 1));
    return 0;
}