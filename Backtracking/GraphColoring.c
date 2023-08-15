#include <stdio.h>
#include <stdbool.h>

#define MAX_VERTICES 100

int graph[MAX_VERTICES][MAX_VERTICES];
int colors[MAX_VERTICES];
int numVertices, numColors;


bool isSafe(int v, int c){
    for(int i=0; i<numVertices; i++){
        if(graph[v][i] && colors[i]==c){
            return false;
        }
    }
    return true;
}


// coloring the graph using backtracking
void colorGraph(int v){
    if(v == numVertices){
        // all vertices are colored, print the soln
        for(int i=0; i<numVertices; i++){
            printf("Vertex %d: Color %d\n", i, colors[i]);
        }
        printf("\n");
    }
    else{
        for(int c = 1; c <= numColors; c++){
            if(isSafe(v, c)){
                colors[v] = c;
                colorGraph(v+1);
                colors[v] = 0; //backtrack and try a different color
            }
        }
    }
}


int main(){
    printf("Enter the number of vertices : ");
    scanf("%d", &numVertices);

    printf("Enter the adj matrix (1 if connected 0 if not):\n");
    for(int i=0; i<numVertices; i++){
        for (int j = 0; j < numVertices; j++)
        {
            scanf("%d", &graph[i][j]);
        } 
    }

    printf("Enter the number of colors : ");
    scanf("%d", &numColors);

    printf("Coloring the graph....\n");
    colorGraph(0);

    return 0;
    //
}