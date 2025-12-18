#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int Info;
    struct Node *link;
};

int main()
{
    struct Node *START, *PTR;

    struct Node *node1 = (struct Node*)malloc(sizeof(struct Node));
    struct Node *node2 = (struct Node*)malloc(sizeof(struct Node));
    struct Node *node3 = (struct Node*)malloc(sizeof(struct Node));

    node1->Info = 10;
    node2->Info = 20;
    node3->Info = 30;

    node1->link = node2;
    node2->link = node3;
    node3->link = NULL;

    START = node1;
    PTR = START;

    while(PTR != NULL)
    {
        printf("%d\n", PTR->Info);
        PTR = PTR->link;
    }
    return 0;
}