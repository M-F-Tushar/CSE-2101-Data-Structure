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
    struct Node *newNode = malloc(sizeof(struct Node));
    newNode->info  = value;
    newNode->left  = NULL;
    newNode->right = NULL;
    return newNode;
}

struct Node* insert(struct Node *root, int value)
{
    if (root == NULL)
    {
        printf("Inserting %d\n", value);
        return createNode(value);
    }

    if (value == root->info)
    {
        printf("%d already exists in the tree!\n", value);
    }
    else if (value < root->info)
    {
        root->left  = insert(root->left,  value);   // Go left
    }
    else
    {
        root->right = insert(root->right, value);   // Go right
    }

    return root;
}

void inorder(struct Node *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        printf("%d ", root->info);
        inorder(root->right);
    }
}

int main()
{
    struct Node *root = NULL;

    root = insert(root, 38);
    root = insert(root, 14);
    root = insert(root, 56);
    root = insert(root, 8);
    root = insert(root, 23);
    root = insert(root, 38);   // Duplicate - should show message

    printf("\nInorder (sorted): ");
    inorder(root);
    printf("\n");

    return 0;
}
