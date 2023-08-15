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

int minDistance(){

}



int main(){
    printf("Enter the number of vertices : ");
    scanf("%d", &numVertices);

    printf("Enter the adj matrix (1 if edge, 0 if edge not):\n");
    for(int i=0; i<numVertices; i++){
        for(int j=0; j<numVertices; j++){
            scanf("%d", &graph[i][j]);
        }
    }

    int source;
    printf("Enter the source vertex :");
    scanf("%d", &source);

    dijkstra(source);

    printf("Shortest distances from vertex %d to other vertices : \n", source);
    for(int v = 0; v<numVertices; v++){
        printf("Vertex %d : Distance %d", v, dist[v]);
    }


    return 0;
}