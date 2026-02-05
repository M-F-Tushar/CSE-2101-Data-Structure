#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int INFO;
    struct Node *LINK;
};

int main()
{
    struct Node *TOP = NULL;
    struct Node *AVAIL = NULL;
    struct Node *NEW;
    struct Node *TEMP;
    int ITEM;

    struct Node *Node1 = malloc(sizeof(struct Node));
    struct Node *Node2 = malloc(sizeof(struct Node));
    
    AVAIL = Node1;
    Node1->LINK = Node2;
    Node2->LINK = NULL;

    //Push 10
    NEW = AVAIL;
    AVAIL = AVAIL->LINK;
    NEW->INFO = 10;
    NEW->LINK = TOP;
    TOP = NEW;

    //Push 20
    NEW = AVAIL;
    AVAIL = AVAIL->LINK;
    NEW->INFO = 20;
    NEW->LINK = TOP;
    TOP = NEW;

    if(TOP == NULL)
    {
        printf("UNDERFLOW\n");
        return 0;
    }

    ITEM = TOP->INFO;

    TEMP = TOP;
    TOP = TOP->LINK;

    TEMP->LINK = AVAIL;
    AVAIL = TEMP;

    printf("Popped Item: %d\n", ITEM);

    printf("Stack After Pop:");
    struct Node *PTR = TOP;

    while(PTR != NULL)
    {
        printf(" %d", PTR->INFO);
        PTR = PTR->LINK;
    }
    return 0;


}