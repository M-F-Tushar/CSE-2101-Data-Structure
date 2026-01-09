#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int INFO;
    struct Node *FORW;
    struct Node *BACK;
};

int main()
{
    struct Node *START, *AVAIL, *LOC;
    struct Node *Node1, *Node2, *Node3, *FreeNode;

    Node1 = malloc(sizeof(struct Node));
    Node2 = malloc(sizeof(struct Node));
    Node3 = malloc(sizeof(struct Node));

    Node1->INFO = 10;
    Node1->BACK = NULL;
    Node1->FORW = Node2;

    Node2->INFO = 20;
    Node2->BACK = Node1;
    Node2->FORW = Node3;

    Node3->INFO = 30;
    Node3->BACK = Node2;
    Node3->FORW = NULL;

    START = Node1;

    FreeNode = malloc(sizeof(struct Node));
    FreeNode->FORW = NULL;
    AVAIL = FreeNode;

    LOC = Node2;

    LOC->BACK->FORW = LOC->FORW;
    LOC->FORW->BACK = LOC->BACK;

    LOC->FORW = AVAIL;
    AVAIL = LOC;
    
    printf("List after deletion:\n");
    struct Node *PTR = START;
    while (PTR != NULL)
    {
        printf("%d ", PTR->INFO);
        PTR = PTR->FORW;
    }

    return 0;
}
