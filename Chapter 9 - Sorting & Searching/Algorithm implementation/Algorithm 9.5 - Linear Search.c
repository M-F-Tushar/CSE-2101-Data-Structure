#include <stdio.h>

int main()
{
    int A[] = {17, 12, 18, 5, 7, 8, 10};
    int n = 7;
    int item = 7;
    int location = -1;

    for (int i = 0; i < n; i++)
    {
        if (A[i] == item)
        {
            location = i;
            break;
        }
    }

    if (location != -1)
    {
        printf("Item %d found at index %d.\n", item, location);
    }
    else
    {
        printf("Item %d not found.\n", item);
    }

    return 0;
}