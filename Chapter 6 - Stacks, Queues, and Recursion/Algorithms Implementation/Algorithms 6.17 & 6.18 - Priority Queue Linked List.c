#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int INFO;
    int PRN;
    struct Node *LINK;
};

struct Node *START = NULL;

void INSERT(int info, int prn)
{
    struct Node *NEW = malloc(sizeof(struct Node));
    NEW->INFO = info;
    NEW->PRN  = prn;
    NEW->LINK = NULL;

    if (START == NULL || prn < START->PRN)
    {
        NEW->LINK = START;
        START     = NEW;
        return;
    }

    struct Node *PTR = START;
    while (PTR->LINK != NULL && PTR->LINK->PRN <= prn)
        PTR = PTR->LINK;

    NEW->LINK = PTR->LINK;
    PTR->LINK = NEW;
}

int DELETE()
{
    if (START == NULL)
    {
        printf("UNDERFLOW\n");
        return -1;
    }

    struct Node *TEMP = START;
    int ITEM = TEMP->INFO;
    START = START->LINK;
    free(TEMP);

    return ITEM;
}

int main()
{
    INSERT(10, 3);
    INSERT(20, 1);
    INSERT(30, 2);
    INSERT(40, 1);
    INSERT(50, 4);

    printf("Priority Queue (sorted by priority number):\n");
    printf("INFO  PRN\n");
    struct Node *PTR = START;
    while (PTR != NULL)
    {
        printf("%-6d%d\n", PTR->INFO, PTR->PRN);
        PTR = PTR->LINK;
    }

    printf("\nDeleting elements by priority:\n");
    while (START != NULL)
    {
        int item = DELETE();
        printf("Deleted: %d\n", item);
    }

    return 0;
}
