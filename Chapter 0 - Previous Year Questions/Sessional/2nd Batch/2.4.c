#include <stdio.h>

#define MAX 50

int STACK[MAX];
int TOP = -1;

void PUSH(int ITEM)
{
    if (TOP == MAX - 1)         
    {
        printf("OVERFLOW\n");
        return;
    }

    TOP = TOP + 1;              
    STACK[TOP] = ITEM;          
}

int POP()
{
    if (TOP == -1)              
    {
        printf("UNDERFLOW\n");
        return -1;
    }

    int ITEM = STACK[TOP];      
    TOP = TOP - 1;              
    return ITEM;                
}

void DISPLAY()
{
    if (TOP == -1)
    {
        printf("Stack is empty.\n");
        return;
    }
    printf("Stack (top to bottom): ");
    for (int i = TOP; i >= 0; i--)
    {
        printf("%d ", STACK[i]);
    }
    printf("\n");
}

int main()
{
    // Push three elements
    PUSH(10);
    PUSH(20);
    PUSH(30);

    printf("After pushing 10, 20, 30:\n");
    DISPLAY();

    // Pop all elements one by one
    printf("\nPopping elements:\n");
    printf("Popped: %d\n", POP());
    printf("Popped: %d\n", POP());
    printf("Popped: %d\n", POP());

    return 0;
}