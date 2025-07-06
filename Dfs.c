#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int adj[MAX][MAX];    // Adjacency matrix
int visited[MAX];     // Visited array

// DFS Function
void dfs(int vertex, int n) {
    visited[vertex] = 1;
    printf("%d ", vertex);

    for (int i = 0; i < n; i++) {
        if (adj[vertex][i] == 1 && !visited[i]) {
            dfs(i, n);
        }
    }
}

int main() {
    int vertices, edges;
    int u, v, start;

    printf("Enter number of vertices: ");
    scanf("%d", &vertices);

    printf("Enter number of edges: ");
    scanf("%d", &edges);

    // Initialize matrices
    for (int i = 0; i < vertices; i++) {
        visited[i] = 0;
        for (int j = 0; j < vertices; j++) {
            adj[i][j] = 0;
        }
    }

    // Read edges
    printf("Enter edges (format: u v):\n");
    for (int i = 0; i < edges; i++) {
        scanf("%d %d", &u, &v);
        adj[u][v] = 1;
        adj[v][u] = 1; // For undirected graph
    }

    printf("Enter starting vertex for DFS: ");
    scanf("%d", &start);

    printf("DFS traversal starting from vertex %d: ", start);
    dfs(start, vertices);
    printf("\n");

    return 0;
}
