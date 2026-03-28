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
    
    display();
    
    return 0;
}
