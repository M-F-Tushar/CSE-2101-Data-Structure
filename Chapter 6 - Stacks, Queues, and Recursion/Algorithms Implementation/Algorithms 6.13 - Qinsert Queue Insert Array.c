#include <stdio.h>

#define N 5

int main()
{
    int QUEUE[N];
    int FRONT = -1, REAR = -1;
    int ITEM = 40;

    QUEUE[0] = 10; 
    FRONT = 0; 
    REAR = 0;
  
    REAR = 1; 
    QUEUE[REAR] = 20;
  
    REAR = 2; 
    QUEUE[REAR] = 30;

    printf("Queue Before Insert: ");
    for (int i = FRONT; i <= REAR; i++)
        printf("%d ", QUEUE[i]);

    if ((FRONT == 0 && REAR == N - 1) || (FRONT == REAR + 1))
    {
        printf("\nOVERFLOW\n");
        return 0;
    }

    if (FRONT == -1)
    {
        FRONT = 0;
        REAR  = 0;
    }
    else if (REAR == N - 1)
    {
        REAR = 0;
    }
    else
    {
        REAR = REAR + 1;
    }

    QUEUE[REAR] = ITEM;

    printf("\nQueue After Insert (ITEM = %d):\n", ITEM);
    int i = FRONT;
    while (1)
    {
        printf("%d ", QUEUE[i]);
        if (i == REAR) break;
        i = (i + 1) % N;
    }

    return 0;
}
