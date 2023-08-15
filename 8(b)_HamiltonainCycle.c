#include <stdio.h>
#include <stdbool.h>

#define MAX_VERTICES 10

int graph[MAX_VERTICES][MAX_VERTICES];
int numVertrtices;


bool isSafe(int v, int path[], int pos){
    if(!graph[path[pos-1]][v]){
        return false;
    }
    for(int i=0; i<pos; i++){
        if(path[i]==v){
            return false;
        }
    }
    return true;

}

int hamiltonianCycle(int path[], int pos){
    if(pos == numVertrtices){
        if(graph[path[pos-1]][path[0]]){
            return 1; //found ham cycle
        }
        return 0;
    }

    for(int v = 1; v < numVertrtices; v++){
        if(isSafe(v, path, pos)){
            path[pos] = v;
            if(hamiltonianCycle(path, pos+1)){
                return 1;
            }
            path[pos] = -1; //backtrack step
        }
    }

    return 0;
}


int main(){
    printf("Enter total vertices : ");
    scanf("%d", &numVertrtices);

    printf("Enter the adj matrix (1 is conn, 0 if not)\n");
    for(int i=0; i<numVertrtices; i++){
        for (int j = 0; j < numVertrtices; j++){
            scanf("%d", &graph[i][j]);
        }
    }

    int path[MAX_VERTICES];
    // initialize the path arr with -1 (means not visited)
    for(int i=0; i<numVertrtices; i++){
        path[i] = -1;
    }

    //starting from vertex 0 which means visited 0
    path[0] = 0;
    
    printf("Finding Hamiltonian Cycle...\n");

    if(hamiltonianCycle(path, 1)){
        printf("Hamiltonian Cycle Found\n");
        for(int i=0; i<numVertrtices; i++){
            printf("%d ", path[i]);
        }
        printf("%d\n", path[0]); //return to the starting vertex
    }
    else{
        printf("No hamiltonian cycle found\n");
    }
}