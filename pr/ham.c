#include <stdio.h>
#include <stdbool.h>

#define MAX_VERTICES 10

int graph[MAX_VERTICES][MAX_VERTICES];
int numVertices;
int path[MAX_VERTICES];


bool isSafe(int v, int path[], int pos){
    return graph[path[pos-1]][v] && !path[v];
}


int hamUtil(int pos){
    if(pos == numVertices){
        return graph[path[pos-1]][path[0]];
    }

    for(int v=0; v<numVertices; v++){
        if(isSafe(v, path, pos)){
            path[pos] = v;
            if(hamUtil(pos+1)){
                return 1; //continue exploring
            }
            path[pos] = -1; //backtracking step
        }
    }


    return 0;
}

int main(){
    printf("Enter the number of vertices : \n");
    scanf("%d", &numVertices);

    printf("Enter the adj matrix :");
    for(int i=0; i<numVertices; i++){
        for(int j=0; j<numVertices; j++){
            scanf("%d", &graph[i][j]);
        }
    }

    // after takin inpu of the garph next define a path array that will keep track of the path and initially initialize it to -1
    for(int i=0; i<numVertices; i++){
        path[i] = -1;
    }
    // since we are starting from 0, we make path[0] = 0
    path[0] = 0;


    printf("Finding ham cycle....\n");



    if(hamUtil(1)){
        printf("Ham cycle exists");
        for(int i=0; i<numVertices; i++){
            printf("%d ", path[i]);
        }
        printf("%d\n", path[0]);
    }
    else{
        printf("No ham cycle");
    }

    return 0;

}