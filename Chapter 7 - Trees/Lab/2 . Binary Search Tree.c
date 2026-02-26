#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int info;
    struct Node* left;
    struct Node *right;
};

struct Node* createNode(int value)
{
    struct Node *New = malloc(sizeof(struct Node));
    New->info = value;
    New->left = NULL;
    New->right = NULL;

    return New;
}


struct Node* insert(struct Node* root, int value)
{
    if(root == NULL)
    {
        return createNode(value);
    }

    if(value < root->info)
    {
        root->left = insert(root->left, value);
    }
    else if(value > root->info)
    {
        root->right = insert(root->right, value);
    }

    return root;
}

struct Node* findMin(struct Node* root)
{
    while(root->left != NULL)
    {
        root = root->left;
    }
    return root;
}


struct Node* delete(struct Node* root, int value)
{
    if(root == NULL)
    {
        return root;
    }

    if(value < root->info)
    {
        root->left = delete(root->left, value);
    }
    else if(value > root->info)
    {
        root->right = delete(root->right, value);
    }
    else
    {
        // Case 1
        if(root->left == NULL & root->right == NULL)
        {
            free(root);
            return NULL;
        }
        // Case 2
        else if(root->left == NULL)
        {
            struct Node* temp = root->right;
            free(root);
            return temp;
        }
        else if(root->right == NULL)
        {
            struct Node* temp = root->left;
            free(root);
            return temp;
        }
        //Case 3
        struct Node* temp = findMin(root->right);
        
        root->info = temp->info;

        root->right = delete(root->right, temp->info);
    }
    return root;
}

int search(struct Node* root, int value)
{
    if(root == NULL)
    {
        return 0;
    }
    if(value == root->info)
    {
        return 1;
    }
    else if(value < root->info)
    {
        return search(root->left, value);
    }
    else
    {
        return search(root->right, value);
    }
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

    root = insert(root, 50);
    insert(root, 30);
    insert(root, 70);
    insert(root, 20);
    insert(root, 40);
    insert(root, 60);
    insert(root, 80);

    printf("Preorder traversal: ");
    preorder(root);

    printf("\nInorder traversal: ");
    inorder(root);

    printf("\nPostorder traversal: ");
    postorder(root);

    if(search(root, 40))
    {
        printf("\n40 found in the tree.\n");
    }
    else
    {
        printf("\n40 not found in the tree.\n");
    }

    // Delete
    root = delete(root, 20);

    printf("\nPreorder traversal after deleting 20: ");
    preorder(root);

    printf("\nInorder traversal after deleting 20: ");
    inorder(root);

    printf("\nPostorder traversal after deleting 20: ");
    postorder(root);

    return 0;





}
