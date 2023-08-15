#include <stdio.h>
#include <stdbool.h>

#define MAX_VERTICES 100

int graph[MAX_VERTICES][MAX_VERTICES];
int colors[MAX_VERTICES];

int numVertices, numColors;


bool isSafe(int vertex, int color){
    for(int i=0; i<numVertices; i++){
        if(color[v][i] && colors[i] == color){
            return false;
        }
    }
    return true;
}

void colorGraph(int v){ //here v is the starting point
    //if position is equal to numVertices then print the colors assigned to graph, since we are checking it with the is safe function it will only return the correct result
    if(v == numVertices){
        for(int i=0; i<numVertices; i++){
            printf("Vertex %d : Color %d", v, colors[v]);
        }
        printf("\n");
    }

    for(int c=1; c<=numColors; c++){
        if(isSafe(v, c)){
            colors[v] = c;
            colorGraph(v+1);

            //backtracking step
            colors[v] = 0;
        }
    }
}

int main(){
    printf("Enter the total number of vertices : ");
    scanf("%d", &numVertices);

    printf("Enter the adj matrix : \n");
    for(int i=0; i<numVertices; i++){
        for(int j=0; j<numVertices; j++){
            scanf("%d", &graph[i][j]);
        }
    }

    printf("Enter the total number of colors : ");
    scanf("%d", &numColors);

    printf("Coloring the graph....\n");
    colorGraph(0);

    return 0;
}