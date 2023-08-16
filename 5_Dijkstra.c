#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

#define MAX_VERTICES 100
#define INF INT_MAX

int graph[MAX_VERTICES][MAX_VERTICES];
int dist[MAX_VERTICES];
bool visited[MAX_VERTICES];
int numVertices;

int minDistance() {
    int minDist = INF, minVertex;
    for (int v = 0; v < numVertices; v++) {
        if (!visited[v] && dist[v] < minDist) {
            minDist = dist[v];
            minVertex = v;
        }
    }
    return minVertex;
}

void dijkstra(int source) {
    for (int v = 0; v < numVertices; v++) {
        dist[v] = INF;
        visited[v] = false;
    }

    dist[source] = 0;

    for (int count = 0; count < numVertices - 1; count++) {
        int u = minDistance();
        visited[u] = true;

        for (int v = 0; v < numVertices; v++) {
            if (!visited[v] && graph[u][v] && dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }
}

int main() {
    printf("Enter the number of vertices: ");
    scanf("%d", &numVertices);

    printf("Enter the adjacency matrix (weight if edge, 0 if no edge):\n");
    for (int i = 0; i < numVertices; i++) {
        for (int j = 0; j < numVertices; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    int source;
    printf("Enter the source vertex: ");
    scanf("%d", &source);

    dijkstra(source);

    printf("Shortest distances from vertex %d to other vertices:\n", source);
    for (int v = 0; v < numVertices; v++) {
        printf("Vertex %d: Distance %d\n", v, dist[v]);
    }

    return 0;
}
