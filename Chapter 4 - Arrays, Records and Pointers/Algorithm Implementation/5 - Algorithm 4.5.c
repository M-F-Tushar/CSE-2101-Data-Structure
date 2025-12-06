#include <stdio.h>
int main()
{
    int DATA[100] = {45, 12, 78, 34, 23};
    int N = 5;
    int ITEM = 78;
    int LOC;

    DATA[N] = ITEM;
    LOC = 0;

    while(DATA[LOC] != ITEM)
    {
        LOC++;
    }
    if(LOC == N)
    {
        LOC = -1;
    }

    if (LOC == -1)
        printf("item not found");
    else
        printf("Item found at index %d\n", LOC);
    
    return 0;
}