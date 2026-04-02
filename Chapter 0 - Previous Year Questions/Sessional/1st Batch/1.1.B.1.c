/*
Write a program which removes the first elements of a linked list (i.e., LIST(INFO, LINK, START)) and adds it to the end of the linked list without changing any values in INFO.
Only START and LINK may be changed. (60)
*/
#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int INFO;
    struct Node *LINK;
};

int main()
{
    struct Node *START, *PTR, *FIRST;
    struct Node *Node1, *Node2, *Node3, *Node4;

    Node1 = malloc(sizeof(struct Node));
    Node2 = malloc(sizeof(struct Node));
    Node3 = malloc(sizeof(struct Node));
    Node4 = malloc(sizeof(struct Node));

    Node1->INFO = 10;
    Node1->LINK = Node2;

    Node2->INFO = 20;
    Node2->LINK = Node3;

    Node3->INFO = 30;
    Node3->LINK = Node4;

    Node4->INFO = 40;
    Node4->LINK = NULL;

    START = Node1;

    /*Check for empty or single-node list  */
    if (START == NULL || START->LINK == NULL)
    {
        printf("Nothing to move.\n");
        return 0;
    }

    /*Save the first node, then detach it (Delete at Beginning) */
    FIRST     = START;        
    START     = START->LINK;  
    FIRST->LINK = NULL;       

    /* Traverse to the last node ── */
    PTR = START;
    while (PTR->LINK != NULL)
    {
        PTR = PTR->LINK;
    }

    /* Attach the saved node at the end (Insert at End)*/
    PTR->LINK = FIRST;       

    /* ── Print result ── */
    printf("List after moving first node to end:\n");
    PTR = START;
    while (PTR != NULL)
    {
        printf("%d ", PTR->INFO);
        PTR = PTR->LINK;
    }
    printf("\n");

    return 0;
}
