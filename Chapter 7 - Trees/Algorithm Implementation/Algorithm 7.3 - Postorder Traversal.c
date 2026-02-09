#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int INFO;
    struct Node *LEFT;
    struct Node *RIGHT;
};

struct Node* createNode(int value)
{
    struct Node *newNode = malloc(sizeof(struct Node));
    newNode->INFO = value;
    newNode->LEFT = NULL;
    newNode->RIGHT = NULL;
    return newNode;

};

void POSTORDER(struct Node *ROOT)
{
    if(ROOT == NULL)
    {
        return;
    }

    POSTORDER(ROOT->LEFT);

    POSTORDER(ROOT->RIGHT);

    printf("%d ", ROOT->INFO);
}

int main()
{
    struct Node *ROOT = createNode(10);
    ROOT->LEFT = createNode(5);
    ROOT->RIGHT = createNode(20);
    ROOT->LEFT->LEFT = createNode(3);
    ROOT->LEFT->RIGHT = createNode(7);
    ROOT->RIGHT->RIGHT = createNode(30);

    printf("Postorder Traversal: ");
    POSTORDER(ROOT);
    return 0;

}