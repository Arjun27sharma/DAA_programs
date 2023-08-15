#include <stdio.h>



void merge(int arr[], int left[], int leftSize, int right[], int rightSize){
    int i = 0, j = 0, k = 0;

    while(i < leftSize && j < rightSize){
        if(left[i] < right[j]){
            arr[k++] = left[i++];
        }
        else{
            arr[k++] = right[j++];
        }
    }
    while(i < leftSize){
        arr[k++] = left[i++];
    }
    while (j < rightSize)
    {
        arr[k++] = right[j++];
    }
    

}

void mergeSort(int arr[], int n){
    if(n<=1){
        return;//base case array is already sorted
    }

    int mid = n/2;

    //create left and right subarrays
    int left[mid];
    int right[n-mid];

    //copy element to left and right subarrays
    for(int i=0; i<mid; i++){
        left[i] = arr[i];
    }
    for(int i=mid; i<n; i++){
        right[i] = arr[i];
    }

    //recursively sort both subarrays
    mergeSort(left, mid);
    mergeSort(right, n-mid);

    //after reaching a point we need to merge the left and right subarrays by checking whih is greater etc..
    merge(arr, left, mid, right, n-mid);
}



int main(){
    int arr[] = {6,2,8,1,5,7,4,3};
    int n = sizeof(arr)/sizeof(arr[0]);


}