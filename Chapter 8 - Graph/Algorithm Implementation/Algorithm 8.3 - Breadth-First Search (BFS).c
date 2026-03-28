#include <stdio.h>

#define MAX 10

int adj[MAX][MAX];  
int visited[MAX];   
int queue[MAX];    
int front, rear;    
int n;             

// Queue operations
void enqueue(int v) 
{ 
    queue[rear++] = v; 
}
int dequeue()      
{ 
    return queue[front++]; 
}
int isEmpty()      
{ 
    return front == rear; 
}

// Add undirected edge
void addEdge(int u, int v) 
{
    adj[u][v] = 1;
    adj[v][u] = 1;
}

void BFS(int start) 
 {
    front = rear = 0;

    // Visit starting node
    visited[start] = 1;
    enqueue(start);
    printf("BFS Traversal: ");

    while (!isEmpty()) 
    {
        int node = dequeue();       
        printf("%d ", node);

        for (int i = 0; i < n; i++) 
        {
            if (adj[node][i] == 1 && visited[i] == 0) 
            {
                visited[i] = 1;
                enqueue(i);
            }
        }
    }
    printf("\n");
}

int main() {
    n = 8;  // vertices 0..7 (A=0, W=1, P=2, U=3, R=4, M=5, L=6, O=7)

    addEdge(0, 1); // A-W
    addEdge(0, 2); // A-P
    addEdge(1, 3); // W-U
    addEdge(1, 4); // W-R
    addEdge(2, 4); // P-R
    addEdge(3, 5); // U-M
    addEdge(5, 6); // M-L
    addEdge(5, 7); // M-O
    addEdge(6, 7); // L-O

    BFS(0);  // Start from A (vertex 0)

    return 0;
}
