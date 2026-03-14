#include <stdio.h>

#define MAX 10
#define INF 9999

int adj[MAX][MAX];  // weighted adjacency matrix (0 = no edge)
int n;              // number of vertices

void primMST() {
    int inTree[MAX];    // 1 if vertex is already in MST
    int minCost[MAX];   // minimum edge cost to reach this vertex
    int parent[MAX];    // parent of each vertex in MST

    // Initialize all values
    for (int i = 0; i < n; i++) {
        inTree[i]  = 0;
        minCost[i] = INF;
        parent[i]  = -1;
    }

    // Start from vertex 0
    minCost[0] = 0;

    printf("Prim's MST:\n");
    printf("Edge\t\tWeight\n");

    int totalCost = 0;

    for (int step = 0; step < n; step++) {
        // Find the vertex NOT in tree with smallest cost
        int u = -1;
        for (int i = 0; i < n; i++) {
            if (!inTree[i] && (u == -1 || minCost[i] < minCost[u]))
                u = i;
        }

        inTree[u] = 1;  // add u to tree
        totalCost += minCost[u];

        if (parent[u] != -1)
            printf("%d -- %d\t\t%d\n", parent[u], u, adj[parent[u]][u]);

        // Update neighbors of u
        for (int v = 0; v < n; v++) {
            if (adj[u][v] != 0 && !inTree[v] && adj[u][v] < minCost[v]) {
                minCost[v] = adj[u][v];
                parent[v]  = u;
            }
        }
    }

    printf("Total MST Weight = %d\n", totalCost);
}

int main() {
    n = 5;  // 5 vertices: 0..4

    // Weighted undirected graph (0 = no edge)
    int w[5][5] = {
        {0, 2, 0, 6, 0},
        {2, 0, 3, 8, 5},
        {0, 3, 0, 0, 7},
        {6, 8, 0, 0, 9},
        {0, 5, 7, 9, 0}
    };

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            adj[i][j] = w[i][j];

    primMST();
    return 0;
}
