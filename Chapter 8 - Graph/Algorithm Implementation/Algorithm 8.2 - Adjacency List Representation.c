#include <stdio.h>

#define MAX 10       // max vertices
#define MAXEDGE 20   // max neighbors per vertex

int adj[MAX][MAXEDGE];  // adj[i] stores neighbors of vertex i
int count[MAX];         // count[i] = number of neighbors of vertex i
int n;                  // number of vertices

void addEdge(int u, int v) 
{
    adj[u][count[u]++] = v;
    adj[v][count[v]++] = u;  // remove for directed graph
}

void printList() 
{
    printf("Adjacency List:\n");
    for (int i = 0; i < n; i++) 
    {
        printf("Vertex %d: ", i);
        for (int j = 0; j < count[i]; j++) 
        {
            printf("%d ", adj[i][j]);
        }
        printf("\n");
    }
}

int main() 
{
    n = 5;

    addEdge(0, 1);
    addEdge(0, 4);
    addEdge(1, 2);
    addEdge(1, 3);
    addEdge(1, 4);
    addEdge(2, 3);
    addEdge(3, 4);

    printList();
    return 0;
}
