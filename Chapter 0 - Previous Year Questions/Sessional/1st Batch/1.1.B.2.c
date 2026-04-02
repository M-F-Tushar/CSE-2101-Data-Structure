/*
Write a program to implement a STACK containing operations PUSH(STACK, ITEM), 
and POP(STACK, ITEM) based on the usual meaning. (60)
*/  

#include<stdio.h>

#define MAX 50

int STACK[MAX];
int TOP = -1;

void PUSH(int ITEM)
{
    if(TOP == MAX - 1)
    {
        printf("OVERFLOW\n");
        return;
    }
    TOP = TOP + 1;
    STACK[TOP] = ITEM;
}

int POP()
{
    if(TOP == -1)
    {
        printf("UNDERFLOW\n");
        return -1;
    }
    int ITEM = STACK[TOP];
    TOP = TOP - 1;
    return ITEM;
}

int main()
{
    PUSH(10);
    PUSH(20);
    PUSH(30);

    printf("%d\n", POP());
    printf("%d\n", POP());
    printf("%d\n", POP());

    return 0;
}
