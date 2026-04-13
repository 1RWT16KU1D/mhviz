#include "main.h"

static inline void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void bubbleSort(int arr[], int n)
{
    for (int i = 0; i < n-1; i++)
    {
        for (int j = 0; j < n-i-1; j++)
        {
            if (arr[j] > arr[j+1])
                swap(&arr[j], &arr[j+1]);
        }
    }
}

void selectionSort(int arr[], int n)
{
    for (int i = 0; i < n-1; i++)
    {
        int minIdx = i;

        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[minIdx])
                minIdx = j;
        }

        swap(&arr[minIdx], &arr[i]);
    }
}