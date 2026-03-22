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

struct Node *stack[100];
int top = -1;

void push(struct Node *node)
{
    top++;
    stack[top] = node;
}

struct Node* pop()
{
    struct Node *node = stack[top];
    top--;
    return node;
}

void PreorderStack(struct Node *ROOT)
{
    push(NULL);               // Push NULL as sentinel
    struct Node *PTR = ROOT;

    while (PTR != NULL)
    {
        printf("%d ", PTR->info);    // Process current node

        if (PTR->right != NULL)      // Push right child first
        {
            push(PTR->right);
        }

        if (PTR->left != NULL)       // Go to left child
        {
            PTR = PTR->left;
        }
        else
        {
            PTR = pop();             
        }
    }
}

int main()
{
    struct Node *ROOT = createNode(10);
    ROOT->left        = createNode(5);
    ROOT->right       = createNode(20);
    ROOT->left->left  = createNode(3);
    ROOT->left->right = createNode(7);
    ROOT->right->right = createNode(30);

    printf("Preorder Traversal (Using Stack): ");
    PreorderStack(ROOT);
    printf("\n");

    return 0;
}
