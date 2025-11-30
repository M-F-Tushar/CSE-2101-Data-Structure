#include <stdio.h>
#include <math.h>

long long factorial(int n) {
    long long f = 1;
    for (int i = 1; i <= n; i++)
        f *= i;
    return f;
}

int main() {
    double x = -8.5;
    int a = 25, m = 7;
    int n = 5;

    // Floor & Ceiling
    printf("Floor(%.2f) = %.0f\n", x, floor(x));
    printf("Ceiling(%.2f) = %.0f\n\n", x, ceil(x));

    // Absolute Value
    printf("ABS(%.2f) = %.2f\n\n", x, fabs(x));

    // Modular Arithmetic
    printf("%d mod %d = %d\n\n", a, m, a % m);

    // Summation Σ j from 1 to n
    int sum = 0;
    for (int j = 1; j <= n; j++)
        sum += j;
    printf("Sum Σ j from 1 to %d = %d\n\n", n, sum);

    // Factorial
    printf("%d! = %lld\n\n", n, factorial(n));

    // Exponent & Logarithm
    printf("2^%d = %.0f\n", n, pow(2, n));
    printf("log2(%d) = %.2f\n\n", n, log2(n));

    // Integer Truncation (INT function)
    printf("INT(%.2f) = %d\n", x, (int)x);

    return 0;
}
