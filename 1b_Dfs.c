#include <stdio.h>
#include <stdbool.h>

#define MAX_NODES 100

int graph[MAX_NODES][MAX_NODES];
bool visited[MAX_NODES];
int queue[MAX_NODES];
int front = -1, rear = -1;


// DFS Checking connectivity method
void dfs(int node, int nodes)
{
    visited[node] = true;

    for (int i = 0; i < nodes; i++)
    {
        if (graph[node][i] == 1 && !visited[i])
        {
            dfs(i, nodes);
        }
    }
}

bool is_connected(int nodes)
{
    for (int i = 0; i < nodes; i++)
    {
        visited[i] = false;
    }

    dfs(0, nodes); // starts dfs from node 0

    for (int i = 0; i < nodes; i++)
    {
        if (!visited[i])
        {
            return false;
        }
    }
    return true;
}

int main()
{
    int nodes, edges;
    printf("Enter the number of nodes and edges : ");
    scanf("%d %d", &nodes, &edges);

    printf("Enter the edges (i j): \n");
    for (int i = 0; i < edges; i++)
    {
        int from, to;
        scanf("%d %d", &from, &to);
        graph[from][to] = 1;
    }

    int start;
    printf("Enter the starting node : ");
    scanf("%d", &start);


    if (is_connected(nodes))
    {
        printf("Graph is connected\n");
    }
    else
    {
        printf("Graph is not connected\n");
    }
}