#include <stdio.h>

#define N 5

int main()
{
    int QUEUE[N];
    int FRONT = -1, REAR = -1;
    int ITEM;

    QUEUE[0] = 10;
    FRONT = 0; 
    REAR = 0;
  
    REAR = 1; 
    QUEUE[REAR] = 20;
  
    REAR = 2; 
    QUEUE[REAR] = 30;

    printf("Queue Before Delete: ");
    int i = FRONT;
    while (1)
    {
        printf("%d ", QUEUE[i]);
        if (i == REAR) break;
        i = (i + 1) % N;
    }

    if (FRONT == -1)
    {
        printf("\nUNDERFLOW\n");
        return 0;
    }

    ITEM = QUEUE[FRONT];

    if (FRONT == REAR)
    {
        FRONT = -1;
        REAR  = -1;
    }
    else if (FRONT == N - 1)
    {
        FRONT = 0;
    }
    else
    {
        FRONT = FRONT + 1;
    }

    printf("\nDeleted Item: %d\n", ITEM);

    printf("Queue After Delete: ");
    if (FRONT == -1)
    {
        printf("(empty)");
    }
    else
    {
        i = FRONT;
        while (1)
        {
            printf("%d ", QUEUE[i]);
            if (i == REAR) break;
            i = (i + 1) % N;
        }
    }

    return 0;
}
