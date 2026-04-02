
/*
Write a program to translate the binary search and insertion algorithm into a subprogram BINARY(ARRAY, LB, UB, ITEM, LOC) 
which finds either the location LOC where ITEM appears in ARRAY or the location LOC where ITEM should be inserted into ARRAY. (60)
*/
#include <stdio.h>

void BINARY(int ARRAY[], int LB, int UB, int ITEM, int *LOC)
{
    int BEG = LB;
    int END = UB;
    int MID;

    while (BEG <= END)
    {
        MID = (BEG + END) / 2;

        if (ARRAY[MID] == ITEM)
        {
            *LOC = MID;   // Found location
            return;
        }
        else if (ITEM < ARRAY[MID])
        {
            END = MID - 1;
        }
        else
        {
            BEG = MID + 1;
        }
    }

    // Not found → insertion position
    *LOC = BEG;
}

int main()
{
    int ARRAY[] = {10, 20, 30, 40, 50, 60};
    int n = 6;
    int ITEM, LOC;

    printf("Sorted Array: ");
    for (int i = 0; i < n; i++)
        printf("%d ", ARRAY[i]);

    printf("\n\nEnter item to search: ");
    scanf("%d", &ITEM);

    // Call BINARY
    BINARY(ARRAY, 0, n - 1, ITEM, &LOC);

    // Output result
    if (ARRAY[LOC] == ITEM)
        printf("Item %d found at location: %d\n", ITEM, LOC);
    else
        printf("Item %d not found. It should be inserted at location: %d\n", ITEM, LOC);

    return 0;
}
