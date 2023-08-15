#include <stdio.h>

int num, capacity;
int weights[20], profits[20];


int knap_DP(){
    int dp[num+1][capacity+1];

    for(int i=0; i<num; i++){
        for(int j=0; j<=capacity; j++){
            if(i==0 || j==0){
                dp[i][j] = 0;
            }
            else if(weights[i-1] <= j){
                dp[i][j] = max(weights[i-1] + dp[i-1][j - weights[i-1]], dp[i-1][j]);
            }
            else{
                dp[i][j] = dp[i-1][j];
            }
        }
    }

    return dp[num][capacity];
}

int main(){
    printf("Enter total itens in knapsack : ");
    scanf("%d", &num);

    printf("Enter (weight profit) of all elements : \n");
    for(int i=0; i<num; i++){
        scanf("%d %d", &weights[i], &profits[i]);
    }

    printf("Enter the capacity of knapsack : \n");
    scanf("%d", &capacity);

    int max_prof = knap_DP();
}