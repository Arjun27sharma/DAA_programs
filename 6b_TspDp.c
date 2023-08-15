#include <stdio.h>
#include <limits.h>

#define MAX 10

int min(int a, int b) {
    return (a < b) ? a : b;
}

int n, cost[MAX][MAX], dp[1 << MAX][MAX];

int tsp(int mask, int pos) {
    if (mask == (1 << n) - 1) {
        return cost[pos][0];
    }

    if (dp[mask][pos] != -1) {
        return dp[mask][pos];
    }

    int ans = INT_MAX;
    for (int city = 0; city < n; city++) {
        if ((mask & (1 << city)) == 0 && cost[pos][city] > 0) {
            int newCost = cost[pos][city] + tsp(mask | (1 << city), city);
            ans = min(ans, newCost);
        }
    }

    return dp[mask][pos] = ans;
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

    for (int i = 0; i < (1 << n); i++) {
        for (int j = 0; j < n; j++) {
            dp[i][j] = -1;
        }
    }

    int minCost = tsp(1, 0);

    printf("Minimum cost of the TSP tour: %d\n", minCost);

    return 0;
}
