/*
Write a program which removes the first elements of a linked list (i.e., LIST(INFO, LINK, START)) and adds it to the end of the linked list without changing any values in INFO.
Only START and LINK may be changed. (60)
*/

#include<stdio.h>
#include<stdlib.h>

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

    printf("Original list:\n");
    PTR = START;
    while(PTR != NULL)
    {
        printf("%d ", PTR->INFO);
        PTR = PTR->LINK;
    }
    printf("\n\n");

    if(START != NULL && START->LINK != NULL)
    {
        struct Node *FirstNode = START;

        START = START->LINK;

        PTR = START;

        while(PTR->LINK != NULL)
        {
            PTR = PTR->LINK;
        }

        PTR->LINK = FirstNode;

        FirstNode->LINK = NULL;
    }

    printf("List after removing first and adding to end:\n");
    
    PTR = START;
    while(PTR != NULL)
    {
        printf("%d ", PTR->INFO);
        PTR = PTR->LINK;
    }
    printf("\n");

    return 0;
}
