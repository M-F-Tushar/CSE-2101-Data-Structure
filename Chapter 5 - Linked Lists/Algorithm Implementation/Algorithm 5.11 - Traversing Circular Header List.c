#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int INFO;
    struct Node *LINK;
};

int main()
{
    struct Node *START, *PTR;
    struct Node *Header, *Node1, *Node2, *Node3;

    Header = malloc(sizeof(struct Node));
    Header->INFO = -1;  
    START = Header;

    Node1 = malloc(sizeof(struct Node));
    Node2 = malloc(sizeof(struct Node));
    Node3 = malloc(sizeof(struct Node));

    Node1->INFO = 10;
    Node2->INFO = 20;
    Node3->INFO = 30;

    Header->LINK = Node1;
    Node1->LINK = Node2;
    Node2->LINK = Node3;
    Node3->LINK = Header;  

    PTR = START->LINK;

    while (PTR != START)
    {
        printf("%d ", PTR->INFO);
        PTR = PTR->LINK;
    }

    return 0;
}
