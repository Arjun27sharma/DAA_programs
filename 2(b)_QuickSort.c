#include <stdio.h>
#include <time.h>

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int arr[], int low, int high)
{
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j <= high - 1; j++)
    {
        if (arr[j] < pivot)
        {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }

    swap(&arr[i + 1], &arr[high]);
    return i + 1;
}

void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        int pIndex = partition(arr, low, high);
        quickSort(arr, low, pIndex - 1);
        quickSort(arr, pIndex + 1, high);
    }
}

void printArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main()
{
    int arr[] = {9, 4, 5, 1, 3, 2, 6, 7, 8, 0, 10};
    int size = sizeof(arr) / sizeof(arr[0]);

    printf("Original Array : ");
    printArray(arr, size);

    clock_t startTime = clock();
    quickSort(arr, 0, size - 1);
    clock_t endTime = clock();

    double timeTaken = (double)(endTime - startTime) / CLOCKS_PER_SEC;
    printf("Time taken : %f\n", timeTaken);

    printf("Sorted Array : ");
    printArray(arr, size);
}