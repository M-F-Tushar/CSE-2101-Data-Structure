#include <stdio.h>

#define MAX 100

int heap[MAX];
int n = 0;

void insertHeap(int item)
{
    int ptr, par; // Current, Parent position
    
    n = n + 1;
    
    ptr = n;
    
    while(ptr > 1) // index 1(start) 
    {
        par = ptr / 2;
        
        if(item <= heap[par])
        {
            break;
        }
        else
        {
        heap[ptr] = heap[par];
        ptr = par;
        }
    }
    heap[ptr] = item;
}

int deleteMax()
{
    int item, last, ptr, left, right, child;
    
    if(n == 0)
    {
        printf("Heap is empty\n");
        return -1;
    }
    
    item = heap[1];
    
    last = heap[n];
    
    n = n -1;
    
    ptr = 1;
    
    while(1)
    {
        left = ptr * 2;
        right = ptr * 2 + 1;
        
        if (left > n)
        {
            break;
        }
        
        if (right > n)
        {
            child = left;
        }
        else
        {
            if(heap[left] > heap[right])
            {
                child = left;
            }
            else
            {
                child = right;
            }
        }
        
        if (last >= heap[child])
        {
            break;
        }
        
        heap[ptr] = heap[child];
        
        ptr = child;
    }
    heap[ptr] = last;
    
    return item;
}

void display()
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
    insertHeap(50);
    insertHeap(30);
    insertHeap(40);
    insertHeap(10);
    insertHeap(70);

    printf("Before deletion:\n");
    display();

    printf("Deleted max = %d\n", deleteMax());

    printf("After deletion:\n");
    display();
    
    return 0;
}
