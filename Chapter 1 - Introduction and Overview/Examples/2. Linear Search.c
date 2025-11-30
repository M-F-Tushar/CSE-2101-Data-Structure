#include<stdio.h>
int main()
{
    int a[4] = {10, 20, 30, 40};
    int key = 30;

    for(int i = 0; i < 4; i++)
    {
        if (a[i] == key)
        {
            printf("Found %d at index %d\n", key, i);
        }
    }
}