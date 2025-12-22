#include<stdio.h>
#include<stdlib.h>


struct Node
{
    int INFO;
    struct Node *LINK;
};

int main()
{
    struct Node *START, *AVAIL, *NEW, *Node1, *Node2, *Node3;
    int ITEM;

    Node1 = malloc(sizeof(struct Node));
    Node2 = malloc(sizeof(struct Node));

    Node1->INFO = 10;
    Node1->LINK = Node2;

    Node2->INFO = 20;
    Node2->LINK = NULL;

    START = Node1;

    Node3 = malloc(sizeof(struct Node));
    Node3->LINK = NULL;
    AVAIL = Node3;

    ITEM = 10;

    if (AVAIL == NULL)
    {
        printf("OVERFLOW\n");
        return 0;
    }

    NEW = AVAIL;
    AVAIL = AVAIL->LINK;

    NEW->INFO = ITEM;

    NEW->LINK = START;
    START = NEW;

    printf("List after insertion:\n");
    struct Node *PTR = START;

    while (PTR != NULL)
    {
        printf("%d\n", PTR->INFO);
        PTR = PTR->LINK;
    }
    return 0;




}
