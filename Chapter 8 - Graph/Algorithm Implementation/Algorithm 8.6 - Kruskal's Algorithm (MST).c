#include <stdio.h>
#include <stdlib.h>

#define MAX 100

// Each edge has two endpoints and a weight
struct Edge {
    int u, v, weight;
};

struct Edge edges[MAX];  // all edges of the graph
int parent[MAX];         // union-find parent array
int edgeCount, n;        // total edges, total vertices

// --- Union-Find (to detect cycles) ---

// Find the root of the set that vertex x belongs to
int find(int x) {
    if (parent[x] != x)
        parent[x] = find(parent[x]);  // path compression
    return parent[x];
}

// Merge two sets
void unionSets(int a, int b) {
    parent[find(a)] = find(b);
}

// Comparator for sorting edges by weight
int compare(const void* a, const void* b) {
    return ((struct Edge*)a)->weight - ((struct Edge*)b)->weight;
}

// Add an edge to the edge list
void addEdge(int u, int v, int w) {
    edges[edgeCount].u      = u;
    edges[edgeCount].v      = v;
    edges[edgeCount].weight = w;
    edgeCount++;
}

void kruskalMST() {
    // Initialize union-find: each vertex is its own parent
    for (int i = 0; i < n; i++) parent[i] = i;

    // Sort edges by weight (smallest first)
    qsort(edges, edgeCount, sizeof(struct Edge), compare);

    printf("Kruskal's MST:\n");
    printf("Edge\t\tWeight\n");

    int totalCost = 0;
    int edgesUsed = 0;

    for (int i = 0; i < edgeCount; i++) {
        int u = edges[i].u;
        int v = edges[i].v;
        int w = edges[i].weight;

        // Only add if u and v are in different sets (no cycle)
        if (find(u) != find(v)) {
            unionSets(u, v);
            printf("%d -- %d\t\t%d\n", u, v, w);
            totalCost += w;
            edgesUsed++;

            // MST is complete when we have n-1 edges
            if (edgesUsed == n - 1) break;
        } else {
            printf("%d -- %d\t\tSkipped (cycle)\n", u, v);
        }
    }

    printf("Total MST Weight = %d\n", totalCost);
}

int main() {
    n = 5;          // 5 vertices
    edgeCount = 0;  // start with no edges

    addEdge(0, 1, 2);
    addEdge(1, 2, 3);
    addEdge(0, 3, 6);
    addEdge(1, 3, 8);
    addEdge(1, 4, 5);
    addEdge(2, 4, 7);
    addEdge(3, 4, 9);

    kruskalMST();
    return 0;
}
