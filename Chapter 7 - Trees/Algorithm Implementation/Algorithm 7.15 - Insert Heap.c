#include <stdio.h>

int heap[100];
int n = 0;

void insert(int item)
{
    n = n + 1;
    heap[n] = item;

    int ptr = n;

    while (ptr > 1)
    {
        int parent = ptr / 2;

        if (heap[ptr] > heap[parent])
        {
            // Swap
            int temp = heap[ptr];
            heap[ptr] = heap[parent];
            heap[parent] = temp;

            ptr = parent;
        }
        else
        {
            break;
        }
    }
}

void printHeap()
{
    printf("Heap: ");
    for (int i = 1; i <= n; i++)
    {
        printf("%d ", heap[i]);
    }
    printf("\n");
}

int main()
{
    insert(10);
    insert(20);
    insert(15);
    insert(40);
    insert(50);

    printHeap();

    return 0;
}
