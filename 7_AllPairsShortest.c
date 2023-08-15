#include <stdio.h>

#define MAX_NODES 100
#define INF 999999

int graph[MAX_NODES][MAX_NODES];
int dist[MAX_NODES][MAX_NODES];
int numVertices;

// Initialize the distance matrix with directed edge weight
void initializeDist()
{
    for (int i = 0; i < numVertices; i++)
    {
        for (int j = 0; j < numVertices; j++)
        {
            dist[i][j] = graph[i][j];
        }
    }
}

// Apply Floyd-Warshall algorithm to find shortest distances
void floydWarshall()
{
    for (int k = 0; k < numVertices; k++)
    {
        for (int i = 0; i < numVertices; i++)
        {
            for (int j = 0; j < numVertices; j++)
            {
                if (dist[i][k] + dist[k][j] < dist[i][j])
                {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }
}

int main()
{
    printf("Enter the number of vertices: ");
    scanf("%d", &numVertices);

    printf("Enter the adjacency matrix (1 if edge, 0 for no edge):\n");
    for (int i = 0; i < numVertices; i++)
    {
        for (int j = 0; j < numVertices; j++)
        {
            scanf("%d", &graph[i][j]);
        }
    }

    initializeDist();
    floydWarshall();

    printf("Shortest distances between all pairs of vertices:\n");
    for (int i = 0; i < numVertices; i++)
    {
        for (int j = 0; j < numVertices; j++)
        {
            printf("%d ", dist[i][j]);
        }
        printf("\n");
    }

    return 0;
}
