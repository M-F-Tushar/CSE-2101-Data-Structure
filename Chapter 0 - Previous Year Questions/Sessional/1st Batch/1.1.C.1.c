/*
Write a program which reverse the elements of a linked list, LIST(INFO, LINK, START). (60)
*/

#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int INFO;
    struct Node *LINK;
};

struct Node* REVERSE(struct Node *START)
{
    struct Node *PREV = NULL;
    struct Node *CURR = START;
    struct Node *NEXT = NULL;

    while(CURR != NULL)
    {
        NEXT = CURR->LINK;
        CURR->LINK = PREV;
        PREV = CURR;
        CURR = NEXT;
    }

    return PREV;
}

void DISPLAY(struct Node *START)
{
    while(START != NULL)
    {
        printf("%d -> ", START->INFO);
        START = START->LINK;
    }
    printf("NULL\n");
}

int main()
{
    struct Node *START, *Node1, *Node2, *Node3, *Node4;

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

    printf("Before reverse: ");
    DISPLAY(START);

    START = REVERSE(START);

    printf("After  reverse: ");
    DISPLAY(START);

    return 0;
}
