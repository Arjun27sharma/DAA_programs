#include <stdio.h>

void knapsack(int num, float profits[], float weights[], float capacity){
    float total_profit, left_capacity = capacity, fractions_arr[20];
    int i;

    // making all the fraction initially to 0
    for(int i=0; i<num; i++){
        fractions_arr[i] = 0.0;
    }

    for(i=0; i<num; i++){
        if(weights[i] > left_capacity){
            break;
        }
        else{
            fractions_arr[i] = 1;
            left_capacity -= weights[i];
            total_profit += profits[i];
        }
    }

    if(i < num){
        fractions_arr[i] = left_capacity/weights[i];
    }
    total_profit += fractions_arr[i]*profits[i];

    printf("The Fractions array is : \n");
    for(int i=0; i<num; i++){
        printf("%f ", fractions_arr[i]);
    }

    printf("\nThe total Profit is : \n");
    printf("%f\n", total_profit);
}


int main(){
    float profits[20], weights[20], ratios[20], capacity, temp;
    int num;


    printf("Enter total number of items in knapsack : \n");
    scanf("%d", &num);

    printf("Enter (weight profit) of all elements : \n");
    for(int i=0; i<num; i++){
        scanf("%f %f", &weights[i], &profits[i]);
    }

    printf("Enter the capacity of knapsack : \n");
    scanf("%f", &capacity);

    // generating ratios array by profits/weights ratio
    for(int i=0; i<num; i++){
        ratios[i] = profits[i]/weights[i];
    }

    // arranging all the arrays in descending order as we need most profit by weight ratio first
    for(int i=0; i<num; i++){
        for(int j=i+1; j<num; j++){
            if(ratios[i] < ratios[j]){
                temp = ratios[i];
                ratios[i] = ratios[j];
                ratios[j] = temp;

                temp = profits[i];
                profits[i] = profits[j];
                profits[j] = temp;

                temp = weights[i];
                weights[i] = weights[j];
                weights[j] = temp;
            }
        }
    }

    knapsack(num, profits, weights, capacity);
    return 0;
}