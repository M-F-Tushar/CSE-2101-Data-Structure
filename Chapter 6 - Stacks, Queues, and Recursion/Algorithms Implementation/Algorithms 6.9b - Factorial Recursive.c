#include <stdio.h>

int FACTORIAL(int N)
{
    if (N == 0)
        return 1;

    return N * FACTORIAL(N - 1);
}

int main()
{
    int N = 5;

    printf("Factorial of %d = %d\n", N, FACTORIAL(N));

    return 0;
}
