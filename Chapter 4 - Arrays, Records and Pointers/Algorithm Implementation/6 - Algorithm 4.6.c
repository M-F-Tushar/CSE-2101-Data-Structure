#include<stdio.h>
int main()
{
    int DATA[] = {5, 12, 19, 23, 34, 45, 56};
    int N = 7;
    int LB = 0;
    int UB = 6;
    int ITEM = 23;
    int BEG, END, MID;
    int LOC;

    BEG = LB;
    END = UB;
    MID = (BEG + END)/2;

    while(BEG <= END && DATA[MID] != ITEM)
    {
        if(ITEM < DATA[MID])
        {
            END = MID - 1;
        }
        else
        {
            BEG = MID + 1;
        }
        MID = (BEG + END)/2;
    }

    if(DATA[MID] == ITEM)
    {
        LOC = MID;
    }
    else
    {
        LOC = -1;
    }

    if(LOC == -1)
    {
        printf("Item not found");
    }
    else
    {
        prinf("Item found at index %d\n",LOC);
    }
    return 0;
}