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
    if (root == NULL)        return createNode(value);
    if (value < root->info)  root->left  = insert(root->left,  value);
    if (value > root->info)  root->right = insert(root->right, value);
    return root;
}

// Find the smallest node in a subtree (inorder successor)
struct Node* findMin(struct Node *root)
{
    while (root->left != NULL)
    {
        root = root->left;
    }
    return root;
}

struct Node* deleteNode(struct Node *root, int value)
{
    if (root == NULL)
    {
        printf("%d not found!\n", value);
        return NULL;
    }

    if (value < root->info)
    {
        root->left  = deleteNode(root->left,  value);
    }
    else if (value > root->info)
    {
        root->right = deleteNode(root->right, value);
    }
    else
    {
        // Case A: No children
        if (root->left == NULL && root->right == NULL)
        {
            free(root);
            return NULL;
        }
        // Case B: One child
        else if (root->left == NULL)
        {
            struct Node *temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL)
        {
            struct Node *temp = root->left;
            free(root);
            return temp;
        }
        // Case C: Two children
        else
        {
            // Find inorder successor (smallest in right subtree)
            struct Node *succ = findMin(root->right);

            printf("Deleting %d (Case C: 2 children) -> replacing with successor %d\n",
                   value, succ->info);

            // Copy successor's value into this node
            root->info = succ->info;

            // Delete the successor from right subtree
            root->right = deleteNode(root->right, succ->info);
        }
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

    root = insert(root, 50);
    root = insert(root, 30);
    root = insert(root, 70);
    root = insert(root, 20);
    root = insert(root, 40);
    root = insert(root, 60);
    root = insert(root, 80);
    root = insert(root, 55);

    printf("Before deletion: ");
    inorder(root);
    printf("\n");

    // Case C: Delete 50 (has 2 children)
    root = deleteNode(root, 50);

    printf("After deleting 50: ");
    inorder(root);
    printf("\n");

    return 0;
}
