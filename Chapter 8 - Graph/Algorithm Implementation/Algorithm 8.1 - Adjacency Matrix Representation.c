#include <stdio.h>

#define MAX 10   

int adj[MAX][MAX]; 
int n;              


void addEdge(int u, int v) 
{
    adj[u][v] = 1;
    adj[v][u] = 1;  
}

void printMatrix() 
{
    printf("Adjacency Matrix:\n");
    printf("   ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", i);
    }
    printf("\n");

    for (int i = 0; i < n; i++) 
    {
        printf("%d: ", i);
        for (int j = 0; j < n; j++) 
        {
            printf("%d ", adj[i][j]);
        }
        printf("\n");
    }
}

int main() {
    n = 5;  

    addEdge(0, 1);
    addEdge(0, 4);
    addEdge(1, 2);
    addEdge(1, 3);
    addEdge(1, 4);
    addEdge(2, 3);
    addEdge(3, 4);

    printMatrix();
    return 0;
}
