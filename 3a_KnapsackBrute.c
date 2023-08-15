#include <stdio.h>

int n, capacity;
int weights[20], profits[20];
int maxProfit = 0;



knap_brute(int i, int weight, int profit){

    if(i == n){
        if(weight <= capacity && profit > maxProfit);
    }

    knap_brute(i+1, weight+weights[i], profit + profits[i]);
    knap_brute(i+1, weight, profit);
}


int main(){
    printf("Enter the total number of items in knapsack : \n");
    scanf("%d", &n);

    printf("Enter (weight profit) of all elements : \n");
    for(int i=0; i<n; i++){
        scanf("%d %d", &weights[i], &profits[i]);
    }

    printf("Enter the capacity of knapsack : \n");
    scanf("%d", &capacity);

    knap_brute(0, 0, 0); //start with empty knap
    printf("Max Profit is : %d\n", maxProfit);

    return 0;
}