#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int INFO;
    struct Node *LINK;
};

int main()
{
    struct Node *START, *PTR, *LOC, *Node1, *Node2, *Node3;
    int ITEM;

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

    ITEM  = 25;

    PTR = START;

    while(PTR != NULL)
    {
        if(ITEM < PTR->INFO)
        {
            LOC = NULL;
            break;
        }
        else if(ITEM == PTR->INFO)
        {
            LOC = PTR;
            break;
        }
        else
        {
            PTR = PTR->LINK;
        }
    }

    if(PTR == NULL)
    {
        LOC = NULL;
    }


    if(LOC != NULL)
        printf("Item %d found in the list.\n", ITEM);
    else
        printf("Item %d not found in the list.\n", ITEM);

    return 0;

}   
