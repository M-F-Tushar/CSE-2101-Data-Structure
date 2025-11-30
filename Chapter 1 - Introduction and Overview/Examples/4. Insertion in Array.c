#include<stdio.h>
int main()
{
    int a[5] = {10, 20, 30}, n = 3;
    for(int i = n; i > 1; i--)
    {
        a[i] = a[i - 1];
    }

    a[1] = 15;

    for(int i = 0; i < 4; i++)
    {
        printf("%d ", a[i]);
    }
    return 0;
}