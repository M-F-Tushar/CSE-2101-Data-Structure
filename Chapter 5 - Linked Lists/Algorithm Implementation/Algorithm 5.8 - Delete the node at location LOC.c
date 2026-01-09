#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int INFO;
    struct Node *LINK;
};

int main()
{
    struct Node *START, *PTR, *AVAIL, *LOC, *LOCP, *Node1, *Node2, *Node3;

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

    AVAIL = NULL;

    LOC = Node2;      
    LOCP = Node1;

    if (LOCP == NULL)         
    {
        START = START->LINK;
    }
    else                       
    {
        LOCP->LINK = LOC->LINK;
    }

    LOC->LINK = AVAIL;
    AVAIL = LOC;

    printf("List after deletion:\n");
    PTR = START;
    while (PTR != NULL)
    {
        printf("%d ", PTR->INFO);
        PTR = PTR->LINK;
    }

    return 0;

}