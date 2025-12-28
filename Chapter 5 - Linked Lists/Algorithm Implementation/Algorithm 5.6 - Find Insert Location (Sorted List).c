#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int INFO;
    struct Node *LINK;
};

int main()
{
    struct Node *START, *PTR, *SAVE, *LOC, *Node1, *Node2, *Node3;
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

    ITEM = 25;

    if(START == NULL)
    {
        LOC  = NULL;
    }
    else if(ITEM < START->INFO)
    {
        LOC = NULL;
    }
    else
    {
        SAVE = START;
        PTR = START->LINK;

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

    if(LOC != NULL)
    {
        printf("LOC contain INFO: %d\n", LOC->INFO);
    }
    else
    {
        printf("LOC is NULL\n");
    }
return 0;

}

