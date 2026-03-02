#include <stdio.h>

int main()
{
    int A[] = {17, 19, 28, 30, 45, 55, 58, 61, 63, 67, 72, 76, 80, 89, 99};
    int n = 15;
    int item = 89;
    int location = -1;

    int first = 0;
    int last = n - 1;

    while (first <= last)
    {
        int mid = (first + last) / 2;

        if (A[mid] == item)
        {
            location = mid;
            break;
        }
        else if (item < A[mid])
        {
            last = mid - 1;
        }
        else
        {
            first = mid + 1;
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