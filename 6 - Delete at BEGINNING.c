#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int INFO;
    struct Node *LINK;
};

int main()
{
    struct Node *START, *AVAIL, *LOC, *PTR;
    struct Node *Node1, *Node2, *Node3, *FreeNode;

    Node1 = malloc(sizeof(struct Node));
    Node2 = malloc(sizeof(struct Node));
    Node3 = malloc(sizeof(struct Node));

    Node1->INFO = 10;  
    Node1->LINK = Node2;
    Node2->INFO = 20;  
    Node2->LINK = Node3;
    Node3->INFO = 30;  
    Node3->LINK = NULL;
    START = Node1;

    FreeNode = malloc(sizeof(struct Node));
    FreeNode->LINK = NULL;
    AVAIL = FreeNode;

    if (START == NULL)
    {
        printf("UNDERFLOW\n");
        return 0;
    }

    LOC = START;
    START = START->LINK;

    LOC->LINK = AVAIL;
    AVAIL = LOC;

    PTR = START;
    while (PTR != NULL)
    {
        printf("%d ", PTR->INFO);
        PTR = PTR->LINK;
    }

    return 0;
}
