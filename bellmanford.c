#include <stdio.h>
#include <stdlib.h>

#define INF 1000000

// Structure to represent an edge
struct Edge {
    int src, dest, weight;
};

int main() {
    int V, E, src;

    printf("Enter number of vertices: ");
    scanf("%d", &V);

    printf("Enter number of edges: ");
    scanf("%d", &E);

    struct Edge edge[E];

    printf("Enter edges in format: src dest weight\n");
    for (int i = 0; i < E; i++) {
        scanf("%d %d %d", &edge[i].src, &edge[i].dest, &edge[i].weight);
    }

    printf("Enter the source vertex: ");
    scanf("%d", &src);

    int dist[V];

    // Step 1: Initialize distances
    for (int i = 0; i < V; i++)
        dist[i] = INF;

    dist[src] = 0;

    // Step 2: Relax all edges V - 1 times
    for (int i = 1; i <= V - 1; i++) {
        for (int j = 0; j < E; j++) {
            int u = edge[j].src;
            int v = edge[j].dest;
            int w = edge[j].weight;

            if (dist[u] != INF && dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
            }
        }
    }

    // Step 3: Check for negative-weight cycles
    int hasNegativeCycle = 0;
    for (int j = 0; j < E; j++) {
        int u = edge[j].src;
        int v = edge[j].dest;
        int w = edge[j].weight;

        if (dist[u] != INF && dist[u] + w < dist[v]) {
            hasNegativeCycle = 1;
            break;
        }
    }

    if (hasNegativeCycle) {
        printf("Graph contains a negative weight cycle.\n");
    } else {
        printf("Vertex\tDistance from Source %d\n", src);
        for (int i = 0; i < V; i++) {
            if (dist[i] == INF)
                printf("%d\tINF\n", i);
            else
                printf("%d\t%d\n", i, dist[i]);
        }
    }

    return 0;
}
