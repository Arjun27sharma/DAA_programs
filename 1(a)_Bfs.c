#include <stdio.h>
#include <stdbool.h>

#define MAX_NODES 100

int graph[MAX_NODES][MAX_NODES];
bool visited[MAX_NODES];
int queue[MAX_NODES];
int front = -1, rear = -1;

// basic enqueue function
void enqueue(int node)
{
    if (rear == MAX_NODES - 1)
    {
        printf("Queue is full\n");
    }
    else
    {
        if (front == -1)
        {
            front = 0;
        }
        rear++;
        queue[rear] = node;
    }
}

int dequeue()
{
    if (front == -1)
    {
        printf("Queue is empty\n");
        return -1;
    }
    else
    {
        int node = queue[front];
        front++;
        if (front > rear)
        {
            front = rear = -1;
        }
        return node;
    }
}

void bfs(int start, int nodes)
{
    enqueue(start);
    visited[start] = true;

    printf("Reachable nodes using BFS: ");

    while (front != -1)
    {
        int current = dequeue();
        printf("%d ", current);

        for (int i = 0; i < nodes; i++)
        {
            if (graph[current][i] == 1 && !visited[i])
            {
                enqueue(i);
                visited[i] = true;
            }
        }
    }

    printf("\n");
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

    bfs(start, nodes);

}