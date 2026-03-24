#include<stdio.h>

#define MAXSTK 5

int main()
{
    int STACK[MAXSTK];
    int TOP = -1;
    int ITEM;

    TOP = TOP + 1;
    STACK[TOP] = 50;

    if (TOP < 0)
    {
        printf("UNDERFLOW\n");
        return 0;
    }

    ITEM = STACK[TOP];
    TOP = TOP - 1;

    printf("Popped Item: %d\n", ITEM);

    return 0;
}
