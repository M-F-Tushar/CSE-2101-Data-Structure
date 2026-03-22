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

struct Node* RL_Rotation(struct Node *A)
{
    struct Node *B = A->right;   
    struct Node *C = B->left;    

    B->left  = C->right;
    C->right = B;

    A->right = C->left;
    C->left  = A;

    A->bf = 0;
    B->bf = 0;
    C->bf = 0;

    printf("RL Rotation performed. New root: %d\n", C->info);
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

    struct Node *root       = createNode(10);
    root->bf                = -2;
    root->right             = createNode(30);
    root->right->bf         = +1;
    root->right->left       = createNode(20);

    printf("Before RL Rotation (Inorder): ");
    inorder(root);
    printf("\n");

    // Apply RL rotation
    root = RL_Rotation(root);

    printf("After  RL Rotation (Inorder): ");
    inorder(root);
    printf("\n");


    return 0;
}
