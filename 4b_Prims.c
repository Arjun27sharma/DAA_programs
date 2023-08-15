#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 100
#define INF 999999

int graph[MAX_VERTICES][MAX_VERTICES];

void prim(int graph[MAX_VERTICES][MAX_VERTICES], int numVertices) {
    int parent[numVertices];
    int key[numVertices];
    int mstSet[numVertices];

    for (int i = 0; i < numVertices; i++) {
        key[i] = INF;
        mstSet[i] = 0;
    }

    key[0] = 0;
    parent[0] = -1;

    for (int count = 0; count < numVertices - 1; count++) {
        int u, minKey = INF;
        for (int v = 0; v < numVertices; v++) {
            if (!mstSet[v] && key[v] < minKey) {
                minKey = key[v];
                u = v;
            }
        }

        mstSet[u] = 1;

        for (int v = 0; v < numVertices; v++) {
            if (graph[u][v] && !mstSet[v] && graph[u][v] < key[v]) {
                parent[v] = u;
                key[v] = graph[u][v];
            }
        }
    }

    printf("Minimum Spanning Tree (Prim's algorithm):\n");
    for (int i = 1; i < numVertices; i++)
        printf("%d - %d\n", parent[i], i);
}

int main() {
    int numVertices, numEdges;
    printf("Enter the number of vertices and edges: ");
    scanf("%d %d", &numVertices, &numEdges);

    int graph[MAX_VERTICES][MAX_VERTICES] = {0};
    
    printf("Enter edges and weights (src dest weight):\n");
    for (int i = 0; i < numEdges; i++) {
        int src, dest, weight;
        scanf("%d %d %d", &src, &dest, &weight);
        graph[src][dest] = weight;
        graph[dest][src] = weight;
    }

    prim(graph, numVertices);

    return 0;
}
