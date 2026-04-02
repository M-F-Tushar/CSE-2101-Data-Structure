#include <stdio.h>
#define MAX 20

// Insert value at position
int insert(int A[], int n, int pos, int val)
{
    // Shift elements right
    for (int i = n - 1; i >= pos; i--)
    {
        A[i + 1] = A[i];
    }

    A[pos] = val;   
    n++;           

    return n;      
}

// Delete element at position
int deleteElement(int A[], int n, int pos)
{
    int item = A[pos];

    // Shift elements left
    for (int i = pos; i < n - 1; i++)
    {
        A[i] = A[i + 1];
    }

    n--;  

    printf("Deleted element: %d\n", item);

    return n;   
}


void display(int A[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", A[i]);
    }
    printf("\n");
}

int main()
{
    int A[MAX] = {10, 20, 30, 40, 50};
    int n = 5;

    printf("Original array: ");
    display(A, n);

    // Insert
    n = insert(A, n, 2, 25);
    printf("After INSERT(25 at pos 2): ");
    display(A, n);

    // Delete
    n = deleteElement(A, n, 3);
    printf("After DELETE(pos 3): ");
    display(A, n);

    return 0;
}