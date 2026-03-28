#include <stdio.h>

#define N 12
#define MAXSTACK 50

int LOWER[MAXSTACK], UPPER[MAXSTACK];
int TOP = -1;

void QUICK(int A[], int BEG, int END, int *LOC)
{
    int LEFT = BEG, RIGHT = END, temp;
    *LOC = BEG;

    while (1)
    {
        while (A[*LOC] <= A[RIGHT] && *LOC != RIGHT)
            RIGHT--;

        if (*LOC == RIGHT) return;

        temp = A[*LOC]; 
        A[*LOC] = A[RIGHT]; 
        A[RIGHT] = temp;
      
        *LOC = RIGHT;

        while (A[LEFT] <= A[*LOC] && LEFT != *LOC)
            LEFT++;

        if (*LOC == LEFT) return;

        temp = A[*LOC]; 
        A[*LOC] = A[LEFT]; 
        A[LEFT] = temp;
      
        *LOC = LEFT;
    }
}

int main()
{
    int A[N] = {44, 33, 11, 55, 77, 90, 40, 60, 99, 22, 88, 66};
    int BEG, END, LOC;

    printf("Before Sort:\n");
    for (int i = 0; i < N; i++)
        printf("%d ", A[i]);

    if (N > 1)
    {
        LOWER[++TOP] = 0;
        UPPER[TOP]   = N - 1;
    }

    while (TOP >= 0)
    {
        BEG = LOWER[TOP];
        END = UPPER[TOP--];

        QUICK(A, BEG, END, &LOC);

        if (BEG < LOC - 1)
        {
            LOWER[++TOP] = BEG;
            UPPER[TOP]   = LOC - 1;
        }

        if (LOC + 1 < END)
        {
            LOWER[++TOP] = LOC + 1;
            UPPER[TOP]   = END;
        }
    }

    printf("\nAfter Sort:\n");
    for (int i = 0; i < N; i++)
        printf("%d ", A[i]);

    return 0;
}
