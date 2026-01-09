#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int INFO;
    struct Node *LINK;
};

int main()
{
    struct Node *START, *PTR, *SAVE, *LOC, *LOCP, *Node1, *Node2, *Node3 ;
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

    ITEM = 20;       

   
    if (START == NULL)
    {
        LOC = NULL;
        LOCP = NULL;
    }
    
    else if (START->INFO == ITEM)
    {
        LOC = START;
        LOCP = NULL;
    }
    else
    {
        SAVE = START;
        PTR = START->LINK;

        while (PTR != NULL)
        {
            if (PTR->INFO == ITEM)
            {
                LOC = PTR;
                LOCP = SAVE;
                break;
            }

            SAVE = PTR;
            PTR = PTR->LINK;
        }

        if (PTR == NULL)
        {
            LOC = NULL;
            LOCP = NULL;
        }
    }

    if (LOC != NULL)
        printf("ITEM found: %d\n", LOC->INFO);
    else
        printf("ITEM not found\n");

    return 0;
}
