/*
Q.3. Write and implement the BINARY_TREE_TRAVERSAL(ROOT) algorithms to traverse a binary tree in three standard ways: INORDER(ROOT), PREORDER(ROOT), and POSTORDER(ROOT), where ROOT is the pointer to the root node of the binary tree. Each node contains DATA, LEFT, and RIGHT pointers. Implement each traversal using recursive functions in C/C++. After implementing the algorithms, write a program that allows the user 
to create a binary tree (via manual node linking or insert function), then choose a traversal type to display the sequence of visited nodes. Clearly distinguish the order of node visits for each traversal in your output. (40)
*/

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
