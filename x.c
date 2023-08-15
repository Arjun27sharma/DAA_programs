#include <stdio.h>

#define MAX_NODES 100

void printGraph(int matrix[MAX_NODES][MAX_NODES], int nodes) {
    for (int i = 0; i < nodes; i++) {
        printf("%d", i);

        int outDegree = 0;
        for (int j = 0; j < nodes; j++) {
            if (matrix[i][j] == 1) {
                if (outDegree == 0) {
                    printf(" -> ");
                } else {
                    printf("    ");
                }
                printf("%d", j);
                outDegree++;
            }
        }

        if (outDegree > 0) {
            printf("\n");
        } else {
            printf(" (no outgoing edges)\n");
        }
    }
}

int main() {
    int nodes;
    printf("Enter the number of nodes: ");
    scanf("%d", &nodes);

    int adjacencyMatrix[MAX_NODES][MAX_NODES];
    printf("Enter the adjacency matrix (%d x %d):\n", nodes, nodes);
    for (int i = 0; i < nodes; i++) {
        for (int j = 0; j < nodes; j++) {
            scanf("%d", &adjacencyMatrix[i][j]);
        }
    }

    printf("Graph Representation:\n");
    printGraph(adjacencyMatrix, nodes);

    return 0;
}
