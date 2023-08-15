#include <stdio.h>
#define MAX_VERTICES 100
int graph[MAX_VERTICES][MAX_VERTICES];
int dist[MAX_VERTICES][MAX_VERTICES];
int numVertrtices;

void floyd(){
    for(int k=0; k<numVertrtices; k++){
        for(int i = 0; i<numVertrtices; i++){
            for(int j = 0; j<numVertrtices; j++){
                if(dist[i][k] + dist[k][j] < dist[i][j]){
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }
}


int main(){
    printf("Enter total vertices : ");
    scanf("%d", &numVertrtices);

    printf("Enter the adj matrix");
    for(int i=0; i<numVertrtices; i++){
        for(int j=0; j<numVertrtices; j++){
            scanf("%d", &graph[i][j]);
        }
    }

    //initialize dist to graph values
    for(int i=0; i<numVertrtices; i++){
        for(int j=0; j<numVertrtices; j++){
            dist[i][j] = graph[i][j];
        }
    }

    floyd();


    print("SHortest dist bw all pairs of vertices");

    for(int i=0; i<numVertrtices; i++){
        for(int j=0; i<numVertrtices; j++){
            printf("%d ", dist[i][j]);
        }
    }



}