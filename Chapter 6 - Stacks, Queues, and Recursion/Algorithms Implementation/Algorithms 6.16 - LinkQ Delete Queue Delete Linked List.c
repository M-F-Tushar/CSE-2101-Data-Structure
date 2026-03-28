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
    struct Node *TEMP;
    int ITEM;

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

    NEW = malloc(sizeof(struct Node));
    NEW->INFO = 30; 
    NEW->LINK = NULL;
    REAR->LINK = NEW; 
    REAR = NEW;

    printf("Queue Before Delete: ");
    struct Node *PTR = FRONT;
    while (PTR != NULL)
    {
        printf("%d ", PTR->INFO);
        PTR = PTR->LINK;
    }

    if (FRONT == NULL)
    {
        printf("\nUNDERFLOW\n");
        return 0;
    }

    TEMP  = FRONT;
    ITEM  = TEMP->INFO;
    FRONT = FRONT->LINK;
    free(TEMP);

    printf("\nDeleted Item: %d\n", ITEM);

    printf("Queue After Delete: ");
    PTR = FRONT;
    while (PTR != NULL)
    {
        printf("%d ", PTR->INFO);
        PTR = PTR->LINK;
    }

    return 0;
}
