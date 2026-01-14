#include<stdio.h>

#define MAXSTK 5

int main()
{
    int STACK[MAXSTK];
    int TOP = -1;
    int ITEM = 25;

    if(TOP == MAXSTK - 1)
    {
        printf("OVERFLOW\n");
        return 0;
    }

    TOP = TOP + 1;

    STACK[TOP] = ITEM;

    printf("Stack After Push:\n");
    for(int i = 0; i <= TOP; i++)
    {
        printf("%d ", STACK[i]);
    }

    return 0;


}