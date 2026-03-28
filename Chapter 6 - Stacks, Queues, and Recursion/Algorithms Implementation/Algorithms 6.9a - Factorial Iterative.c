#include <stdio.h>

int main()
{
    int N = 5;
    int FACT;

    if (N == 0)
    {
        FACT = 1;
    }
    else
    {
        FACT = 1;
        for (int K = 1; K <= N; K++)
            FACT = K * FACT;
    }

    printf("Factorial of %d = %d\n", N, FACT);

    return 0;
}
