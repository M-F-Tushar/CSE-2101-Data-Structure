#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int INFO;
    struct Node *LINK;
};

int main()
{
    struct Node *START, *AVAIL, *PTR, *SAVE, *LOC, *NEW, *Node1, *Node2, *Node3;
    int ITEM;

    Node1 = malloc(sizeof(struct Node));
    Node2 = malloc(sizeof(struct Node));

    Node1->INFO = 10;
    Node1->LINK = Node2;

    Node2->INFO = 30;
    Node2->LINK = NULL;

    START = Node1;

    // Creating AVAIL
    Node3 = malloc(sizeof(struct Node));
    Node3->LINK = NULL;
    AVAIL = Node3;

    ITEM = 20;

    if(START == NULL)
    {
        LOC = NULL;
    }
    else if(ITEM < START->INFO)
    {
        LOC = NULL;
    }
    else
    {
        SAVE = PTR;
        PTR = START;

        while(PTR != NULL)
        {
            if(ITEM < PTR->INFO)
            {
                LOC = SAVE;
                break;
            }
            SAVE = PTR;
            PTR = PTR->LINK;
        }

        if(PTR == NULL)
        {
            LOC = SAVE;
        }
    }

    if (AVAIL == NULL)
    {
        printf("OVERFLOW\n");
        return 0;
    }

    NEW = AVAIL;
    AVAIL = AVAIL->LINK;

    NEW->INFO = ITEM;

    if(LOC == NULL)
    {
        NEW->LINK = START;
        START = NEW;
    }
    else
    {
        NEW->LINK = LOC->LINK;
        LOC->LINK = NEW;
    }

    printf("The list after insertion is:\n");
    PTR = START;
    while(PTR != NULL)
    {
        printf("%d\n", PTR->INFO);
        PTR = PTR->LINK;
    }

    return 0;
}