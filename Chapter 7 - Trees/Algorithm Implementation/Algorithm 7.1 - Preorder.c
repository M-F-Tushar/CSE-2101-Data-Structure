#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int info;
    struct Node *left;
    struct Node *right;
};

struct Node* createNode(int value)
{
    struct Node* newNode;
    newNode = malloc(sizeof(struct Node));
    newNode->info = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

void Preorder(struct Node * ROOT)
{
    if(ROOT == NULL)
    {
        return;
    }

    printf("%d ", ROOT->info);

    Preorder(ROOT->left);
    Preorder(ROOT->right);
}

int main()
{
    struct Node *ROOT = createNode(10);
    ROOT->left = createNode(5);
    ROOT->right = createNode(20);
    ROOT->left->left = createNode(3);
    ROOT->left->right = createNode(7);
    ROOT->right->right = createNode(30);

    printf("Preorder Traversal: ");
    Preorder(ROOT); 
    
    return 0;

}
