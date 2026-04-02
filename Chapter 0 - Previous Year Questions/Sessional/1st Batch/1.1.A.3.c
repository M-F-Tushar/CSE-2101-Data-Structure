#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int info;
    struct Node* left;
    struct Node* right;
};

struct Node* newNode(int value)
{
    struct Node *New = malloc(sizeof(struct Node));
    New->info = value;
    New->left = NULL;
    New->right = NULL;
    return New;
}


struct Node* insert(struct Node* root, int val)
{
    if(root == NULL)
    {
        return newNode(val);
    }
    
    if(val < root->info)
    {
        root->left = insert(root->left, val);
    }
    else
    {
        root->right = insert(root->right, val);
    }

    return root;
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
    struct Node* root = NULL;

    int elements[] = {50, 30, 70, 20, 40, 60, 80};
    int n = 7;

    printf("Inserting elements: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", elements[i]);
        root = insert(root, elements[i]);
    }

    printf("\n\nPreorder Traversal: ");
    preorder(root);

    printf("\nInorder Traversal: ");
    inorder(root);

    printf("\nPostorder Traversal: ");
    postorder(root);

    return 0;
}