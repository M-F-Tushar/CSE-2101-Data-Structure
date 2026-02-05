#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int INFO;
    struct Node *Link;
};

int main()
{
    struct Node *Top = NULL;
    struct Node *AVAIL = NULL;
    struct Node *NEW;
    int ITEM = 25;


    struct Node *Node1 = malloc(sizeof(struct Node));
    struct Node *Node2 = malloc(sizeof(struct Node));

    AVAIL = Node1;
    Node1->Link = Node2;
    Node2->Link = NULL;
    
    if(AVAIL == NULL)
    {
        printf("OVERFLOW\n");
        return 0;
    }

    NEW = AVAIL;
    AVAIL = AVAIL->Link;

    NEW->INFO = ITEM;
    NEW->Link = Top;
    Top = NEW;

    printf("Stack After Push:\n");
    struct Node *PTR = Top;

    while(PTR != NULL)
    {
        printf("%d ", PTR->INFO);
        PTR = PTR->Link;
    }

    return 0;
}