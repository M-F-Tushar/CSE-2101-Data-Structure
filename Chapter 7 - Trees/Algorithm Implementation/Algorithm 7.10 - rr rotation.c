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
struct Node* RR_Rotation(struct Node *A)
{
    struct Node *B = A->right;   

    A->right = B->left;          
    B->left  = A;                

    A->bf = 0;
    B->bf = 0;

    printf("RR Rotation performed. New root: %d\n", B->info);
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

    struct Node *root  = createNode(10);
    root->bf           = -2;
    root->right        = createNode(20);
    root->right->bf    = -1;
    root->right->right = createNode(30);

    printf("Before RR Rotation (Inorder): ");
    inorder(root);
    printf("\n");

    root = RR_Rotation(root);

    printf("After  RR Rotation (Inorder): ");
    inorder(root);
    printf("\n");
0

    return 0;
}
