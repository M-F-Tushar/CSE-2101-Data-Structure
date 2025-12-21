#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int INFO;
    struct Node *LINK;
};

int main()
{
    struct Node *START, *PTR, *Node1, *Node2, *Node3;

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

    PTR = START;

    while (PTR != NULL)
    {
        printf("%d\n", PTR->INFO);
        PTR = PTR->LINK;
    }

    return 0;
}

