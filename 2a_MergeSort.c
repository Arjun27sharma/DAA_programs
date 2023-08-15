#include <stdio.h>


void merge(int arr[], int left[], int leftSize, int right[], int rightSize){
    // indexes for left subarray, right subarray and merged array
    int i =0, j = 0, k = 0;

    while(i < leftSize && j < rightSize){
        if(left[i] <= right[j]){
            arr[k++] = left[i++];
        }
        else{
            arr[k++] = right[j++];
        }
    }
    while(i < leftSize){
        arr[k++] = left[i++];

    }
    while(j < rightSize){
        arr[k++] = right[j++];

    }


}

void mergeSort(int arr[], int n){
    if(n <= 1){
        return; //base case array is already sorted or empty
    }

    int mid = n / 2;

    //create left and right subarrays

    int left[mid];
    int right[n - mid];

    
    // copy elements to left and right subarrays

    for(int i=0; i<mid; i++){
        left[i] = arr[i];
    }

    for(int i=mid; i<n; i++){
        right[i-mid] = arr[i];
    }


    // recusrively srot the left and right subarrays
    mergeSort(left, mid);
    mergeSort(right, n-mid);

    // merge the left and right subarrays
    merge(arr, left, mid, right, n-mid);
}

int main(){

    int arr[] = {6,2,8,1,4,9,3,5,7};
    int n = sizeof(arr) / sizeof(arr[0]);


    printf("Original Array: ");

    for(int i=0; i<n; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");

    mergeSort(arr, n);

    printf("Sorted Array : ");
    for(int i=0; i<n; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}