#include <stdio.h>

#define MAX 10

int adj[MAX][MAX];   // adjacency matrix
int visited[MAX];    // 0=not visited, 1=visited
int stack[MAX];      // simple stack
int top;             // stack pointer
int n;               // number of vertices

// Stack operations
void push(int v)  
{ 
    stack[top++] = v; 
}
int pop()        
{ 
    return stack[--top]; 
}
int isEmptyStack() 
{ 
    return top == 0; 
}

// Add undirected edge
void addEdge(int u, int v) 
{
    adj[u][v] = 1;
    adj[v][u] = 1;
}

// DFS starting from vertex start
void DFS(int start) 
{
    top = 0;

    // Push the starting node
    push(start);
    visited[start] = 1;
    printf("DFS Traversal: ");

    while (!isEmptyStack()) 
    {
        int node = pop();          // take from top
        printf("%d ", node);

        // Push all unvisited neighbors onto stack
        for (int i = 0; i < n; i++) {
            if (adj[node][i] == 1 && visited[i] == 0) {
                visited[i] = 1;
                push(i);
            }
        }
    }
    printf("\n");
}

int main() 
{
    n = 8;  // same graph as BFS example

    addEdge(0, 1); // A-W
    addEdge(0, 2); // A-P
    addEdge(1, 3); // W-U
    addEdge(1, 4); // W-R
    addEdge(2, 4); // P-R
    addEdge(3, 5); // U-M
    addEdge(5, 6); // M-L
    addEdge(5, 7); // M-O
    addEdge(6, 7); // L-O

    DFS(0);  // Start from A (vertex 0)

    return 0;
}
