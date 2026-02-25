#include <stdio.h>
#include <stdlib.h>

struct Node 
{
    int info;
    struct Node* left;
    struct Node* right;
};

struct Node* createNode(int value)
{
    struct Node *New = malloc(sizeof(struct Node));
    New->info = value;
    New->left = NULL;
    New->right = NULL;
    return New;
}

void preorder(struct Node* root)
{
    if(root != NULL)
    {
        printf("%d ", root->info);
        preorder(root->left);
        preorder(root->right);
    }
}

void inorder(struct Node* root)
{
    if(root != NULL)
    {
        inorder(root->left);
        printf("%d ", root->info);
        inorder(root->right);
    }
}

void postorder(struct Node* root)
{
    if(root != NULL)
    {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->info);
    }
}

int main()
{
    struct Node* root;

    root = createNode(1);

    root->left = createNode(2);
    root->right = createNode(3);

    root->left->left = createNode(4);
    root->left->right = createNode(5);

    printf("Preorder Traversal: ");
    preorder(root);

    printf("\nInorder Traversal: ");
    inorder(root);

    printf("\nPostorder Traversal: ");
    postorder(root);

    return 0;
}
