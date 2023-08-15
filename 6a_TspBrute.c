#include <stdio.h>
#include <limits.h>

#define MAX 10

int min(int a, int b) {
    return (a < b) ? a : b;
}

int cost[MAX][MAX];
int visited[MAX];
int n, minCost = INT_MAX;

void tsp(int current, int count, int pathCost) {
    if (count == n && cost[current][0] > 0) {
        minCost = min(minCost, pathCost + cost[current][0]);
        return;
    }

    for (int i = 0; i < n; i++) {
        if (!visited[i] && cost[current][i] > 0) {
            visited[i] = 1;
            tsp(i, count + 1, pathCost + cost[current][i]);
            visited[i] = 0;
        }
    }
}

int main() {
    printf("Enter the number of cities: ");
    scanf("%d", &n);

    printf("Enter the cost matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &cost[i][j]);
        }
    }

    for (int i = 0; i < n; i++) {
        visited[i] = 0;
    }
    visited[0] = 1;

    tsp(0, 1, 0);

    printf("Minimum cost of the TSP tour: %d\n", minCost);

    return 0;
}
