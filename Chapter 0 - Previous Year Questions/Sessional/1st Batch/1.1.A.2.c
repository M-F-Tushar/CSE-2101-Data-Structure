#include <stdio.h>

#define MAX 5

int QUEUE[MAX];
int FRONT = -1, REAR = -1;

void ENQUEUE(int ITEM)
{
    if (REAR == MAX - 1)
    {
        printf("OVERFLOW: Queue is Full\n");
        return;
    }
    if (FRONT == -1)
    {
        FRONT = 0;
        REAR = 0;
    }
    else
    {
        REAR = REAR + 1;
    }
    QUEUE[REAR] = ITEM;
    printf("Enqueued: %d\n", ITEM);
}

void DEQUEUE()
{
    if (FRONT == -1)
    {
        printf("UNDERFLOW: Queue is Empty\n");
        return;
    }
    int ITEM = QUEUE[FRONT];
    printf("Dequeued: %d\n", ITEM);

    if (FRONT == REAR)
    {
        FRONT = -1;
        REAR = -1;
    }
    else
    {
        FRONT = FRONT + 1;
    }
}

void display()
{
    if (FRONT == -1)
    {
        printf("Queue is empty.\n");
        return;
    }
    printf("Queue: ");
    for (int i = FRONT; i <= REAR; i++)
    {
        printf("%d ", QUEUE[i]);
    }

    printf("\n");
}

int main()
{
    ENQUEUE(10);
    ENQUEUE(20);
    ENQUEUE(30);
    display();

    DEQUEUE();
    display();

    ENQUEUE(40);
    display();

    return 0;
}