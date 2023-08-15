#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 100
#define INF 999999

struct Edge {
    int src, dest, weight;
};

int parent[MAX_VERTICES];

int find(int i) {
    while (parent[i] != i)
        i = parent[i];
    return i;
}

void unionSets(int i, int j) {
    int a = find(i);
    int b = find(j);
    parent[a] = b;
}

int compare(const void* a, const void* b) {
    return ((struct Edge*)a)->weight - ((struct Edge*)b)->weight;
}

void kruskal(struct Edge edges[], int numEdges, int numVertices) {
    qsort(edges, numEdges, sizeof(struct Edge), compare);

    struct Edge result[numVertices];
    int e = 0, i = 0;

    for (int v = 0; v < numVertices; v++)
        parent[v] = v;

    while (e < numVertices - 1) {
        struct Edge nextEdge = edges[i++];
        int x = find(nextEdge.src);
        int y = find(nextEdge.dest);
        if (x != y) {
            result[e++] = nextEdge;
            unionSets(x, y);
        }
    }

    printf("Minimum Spanning Tree (Kruskal's algorithm):\n");
    for (i = 0; i < e; i++)
        printf("%d - %d\n", result[i].src, result[i].dest);
}

int main() {
    int numVertices, numEdges;
    printf("Enter the number of vertices and edges: ");
    scanf("%d %d", &numVertices, &numEdges);

    struct Edge edges[numEdges];
    
    printf("Enter edges and weights (src dest weight):\n");
    for (int i = 0; i < numEdges; i++) {
        scanf("%d %d %d", &edges[i].src, &edges[i].dest, &edges[i].weight);
    }

    kruskal(edges, numEdges, numVertices);

    return 0;
}
