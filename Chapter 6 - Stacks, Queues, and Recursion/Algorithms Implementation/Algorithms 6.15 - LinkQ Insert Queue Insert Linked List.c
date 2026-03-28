#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int INFO;
    struct Node *LINK;
};

int main()
{
    struct Node *FRONT = NULL;
    struct Node *REAR  = NULL;
    struct Node *NEW;
    int ITEM = 30;

    NEW = malloc(sizeof(struct Node));
    NEW->INFO = 10; 
    NEW->LINK = NULL;
    FRONT = NEW; 
    REAR = NEW;

    NEW = malloc(sizeof(struct Node));
    NEW->INFO = 20; 
    NEW->LINK = NULL;
    REAR->LINK = NEW; 
    REAR = NEW;

    printf("Queue Before Insert: ");
    struct Node *PTR = FRONT;
    while (PTR != NULL)
    {
        printf("%d ", PTR->INFO);
        PTR = PTR->LINK;
    }

    NEW = malloc(sizeof(struct Node));
    NEW->INFO = ITEM;
    NEW->LINK = NULL;

    if (FRONT == NULL)
    {
        FRONT = NEW;
        REAR  = NEW;
    }
    else
    {
        REAR->LINK = NEW;
        REAR       = NEW;
    }

    printf("\nQueue After Insert (ITEM = %d):\n", ITEM);
    PTR = FRONT;
    while (PTR != NULL)
    {
        printf("%d ", PTR->INFO);
        PTR = PTR->LINK;
    }

    return 0;
}
