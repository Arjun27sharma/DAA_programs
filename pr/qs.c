#include <stdio.h>


int partition(int arr[], int low, int high){
    int pivot = arr[high];
    int i = low-1;

    for(int j=low; j<=high; j++){
        if(arr[j] < pivot){
            i++;
            // swap
        }
    }
    swap(&arr[i+1], &arr[high]);

    return i+1;
}

int quicksort(int arr[], int low, int high){
    if(low < high){
        int pIndex = partition(arr, low, high);
        quicksort(arr, 0, pIndex-1);
        quicksort(arr, pIndex+1, high);
    }

}

int main(){
    int arr[] = {9, 4, 5, 1, 3, 2, 6, 7, 8, 0, 10};
    int size = sizeof(arr) / sizeof(arr[0]);
    quickSort(arr, 0, size - 1);
    for(int i = 0; i < size; i++){
        printf("%d ", arr[i]);
    }
    return 0;

}