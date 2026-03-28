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

void createHeap(int arr[], int size)
{
    int i;
    
    for(i = 0; i < size; i++)
    {
        insertHeap(arr[i]);
    }
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
    int arr[] = {50, 30, 40, 10, 70, 60};
    int size = 6;
    
    createHeap(arr, size);
    
    
    display();
    
    return 0;
}
