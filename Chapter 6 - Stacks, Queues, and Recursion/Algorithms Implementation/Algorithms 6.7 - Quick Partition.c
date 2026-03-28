#include <stdio.h>

#define N 12

int main()
{
    int A[N] = {44, 33, 11, 55, 77, 90, 40, 60, 99, 22, 88, 66};
    int BEG = 0, END = N - 1;
    int LEFT = BEG, RIGHT = END;
    int LOC = BEG;
    int temp;

    printf("Before Partition:\n");
    for (int i = 0; i < N; i++)
        printf("%d ", A[i]);

    while (1)
    {
        while (A[LOC] <= A[RIGHT] && LOC != RIGHT)
            RIGHT--;

        if (LOC == RIGHT)
            break;

        temp = A[LOC]; 
        A[LOC] = A[RIGHT]; 
        A[RIGHT] = temp;
      
        LOC = RIGHT;

        while (A[LEFT] <= A[LOC] && LEFT != LOC)
            LEFT++;

        if (LOC == LEFT)
            break;

        temp = A[LOC]; 
        A[LOC] = A[LEFT]; 
        A[LEFT] = temp;
      
        LOC = LEFT;
    }

    printf("\nAfter Partition:\n");
    for (int i = 0; i < N; i++)
        printf("%d ", A[i]);

    printf("\nPivot Value %d is now at index %d\n", A[LOC], LOC);

    return 0;
}
