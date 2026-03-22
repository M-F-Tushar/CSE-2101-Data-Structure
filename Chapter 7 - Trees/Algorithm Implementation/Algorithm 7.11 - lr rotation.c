#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int info;
    int bf;
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

struct Node* LR_Rotation(struct Node *A)
{
    struct Node *B = A->left;  
    struct Node *C = B->right;   

    B->right = C->left;
    C->left  = B;

    A->left  = C->right;
    C->right = A;

    A->bf = 0;
    B->bf = 0;
    C->bf = 0;

    printf("LR Rotation performed. New root: %d\n", C->info);
    return C;                
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

    struct Node *root        = createNode(30);
    root->bf                 = +2;
    root->left               = createNode(10);
    root->left->bf           = -1;
    root->left->right        = createNode(20);

    printf("Before LR Rotation (Inorder): ");
    inorder(root);
    printf("\n");

    // Apply LR rotation
    root = LR_Rotation(root);

    printf("After  LR Rotation (Inorder): ");
    inorder(root);
    printf("\n");



    return 0;
}
