#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int info;
    int bf;              // Balance factor
    struct Node *left;
    struct Node *right;
};

struct Node* createNode(int value)
{
    struct Node *newNode = malloc(sizeof(struct Node));
    newNode->info  = value;
    newNode->bf    = 0;
    newNode->left  = NULL;
    newNode->right = NULL;
    return newNode;
}

struct Node* LL_Rotation(struct Node *A)
{
    struct Node *B = A->left;    

    A->left  = B->right;         
    B->right = A;                

    A->bf = 0;
    B->bf = 0;

    printf("LL Rotation performed. New root: %d\n", B->info);
    return B;                    // B is new root
}

void inorder(struct Node *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        printf("%d(BF=%d) ", root->info, root->bf);
        inorder(root->right);
    }
}

int main()
{

    struct Node *root = createNode(30);
    root->bf          = +2;
    root->left        = createNode(20);
    root->left->bf    = +1;
    root->left->left  = createNode(10);

    printf("Before LL Rotation (Inorder): ");
    inorder(root);
    printf("\n");

    // Apply LL rotation
    root = LL_Rotation(root);

    printf("After  LL Rotation (Inorder): ");
    inorder(root);
    printf("\n");

    return 0;
}
