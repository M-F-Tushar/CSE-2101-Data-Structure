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

int deleteMax()
{
    if (n == 0)
    {
        printf("Heap is empty!\n");
        return -1;
    }

    int max = heap[1];

    heap[1] = heap[n];
    n = n - 1;

    int ptr = 1;

    while (2 * ptr <= n)
    {
        int left  = 2 * ptr;
        int right = 2 * ptr + 1;
        int larger = left;

        if (right <= n && heap[right] > heap[left])
        {
            larger = right;
        }

        if (heap[ptr] >= heap[larger])
        {
            break;
        }

        // Swap
        int temp = heap[ptr];
        heap[ptr] = heap[larger];
        heap[larger] = temp;

        ptr = larger;
    }

    return max;
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

    int max = deleteMax();
    printf("Deleted Max: %d\n", max);

    printHeap();

    return 0;
}
