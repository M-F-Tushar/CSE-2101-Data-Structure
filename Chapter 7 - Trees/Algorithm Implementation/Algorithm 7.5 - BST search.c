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

// Returns 1 if found, 0 if not found
int search(struct Node *ROOT, int ITEM)
{
    if (ROOT == NULL)         return 0;    // Not found
    if (ITEM == ROOT->info)   return 1;    // Found!
    if (ITEM < ROOT->info)    return search(ROOT->left,  ITEM);
    else                      return search(ROOT->right, ITEM);
}

int main()
{
    struct Node *root = NULL;

    root = insert(root, 38);
    root = insert(root, 14);
    root = insert(root, 56);
    root = insert(root, 8);
    root = insert(root, 23);
    root = insert(root, 45);
    root = insert(root, 82);

    int item = 45;
    if (search(root, item))
        printf("%d is FOUND in the BST.\n", item);
    else
        printf("%d is NOT found in the BST.\n", item);

    item = 99;
    if (search(root, item))
        printf("%d is FOUND in the BST.\n", item);
    else
        printf("%d is NOT found in the BST.\n", item);

    return 0;
}
