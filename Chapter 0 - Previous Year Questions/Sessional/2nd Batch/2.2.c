/*

Q.2. Implement the INSERT_AT_POS algorithm for a doubly linked list to insert a new node
at a specified position. Write the algorithm INSERT_AT_POS(HEAD, POS, VAL), where HEAD is a pointer to the first node of the list, POS is the valid position at which the new node with data VAL is to be inserted (0 for beginning, up to length of the list),
and the list should maintain both next and prev links properly. Ensure that all pointer connections (prev and next) are correctly updated for the new node and its neighbours. After completing the algorithm, implement a C/C++ program that takes input from the user for initial list creation and allows insertion at any valid position, displaying the list after each insertion. (40)
*/
#include <stdio.h>
#include <stdlib.h>

struct Node 
{
    int info;
    struct Node *prev;
    struct Node *next;
};

struct Node* newNode(int val) 
{
    struct Node* n = malloc(sizeof(struct Node));
    n->info = val;
    n->prev = NULL;
    n->next = NULL;
    return n;
}

// Insert at position POS (0-indexed)
struct Node* insertAtPos(struct Node* head, int pos, int val) 
{
    struct Node* NEW = newNode(val);

    // Case 1: Insert at beginning (pos = 0)
    if (pos == 0) 
    {
        NEW->next = head;
        if (head != NULL)
            head->prev = NEW;
        return NEW;  // new head
    }

    // Case 2: Traverse to node just before pos
    struct Node* ptr = head;
    int count = 0;
    while (ptr != NULL && count < pos - 1) 
    {
        ptr = ptr->next;
        count++;
    }

    // Invalid position
    if (ptr == NULL) 
    {
        printf("Invalid position!\n");
        free(NEW);
        return head;
    }

    // Case 3: Insert NEW between ptr and ptr->next
    NEW->next = ptr->next;        // NEW points forward
    NEW->prev = ptr;              // NEW points backward

    if (ptr->next != NULL)        // If there is a node after
        ptr->next->prev = NEW;    // Update that node's prev

    ptr->next = NEW;              // Current node points to NEW
    return head;
}

// Display the list forward
void display(struct Node* head) 
{
    struct Node* ptr = head;
    printf("List: ");
    while (ptr != NULL) {
        printf("[%d]", ptr->info);
        if (ptr->next != NULL) printf(" <-> ");
        ptr = ptr->next;
    }
    printf("\n");
}

int main() {
    struct Node* head = NULL;
    int n, pos, val;

    // Build initial list
    printf("How many initial nodes? ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        printf("Enter value for node %d: ", i);
        scanf("%d", &val);
        head = insertAtPos(head, i, val);
    }

    display(head);

    // Insert at any position
    printf("\nEnter position and value to insert: ");
    scanf("%d %d", &pos, &val);
    head = insertAtPos(head, pos, val);
    printf("After insertion: ");
    display(head);

    return 0;
}
