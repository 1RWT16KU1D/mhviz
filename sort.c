#include "main.h"

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

bool isSorted(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        if (arr[i] > arr[i + 1])
            return FALSE;
    }
    return TRUE;
}

void bubbleStepSort(int *i, int *j, int swappedIndices[], int arr[], int n)
{   
    if (*i >= n - 1)
        return;

    if (*j >= n - *i - 1)
    {
        (*i)++;
        *j = 0;
        return;
    }

    swappedIndices[0] = *j;
    swappedIndices[1] = *j + 1;

    if (arr[*j] > arr[*j + 1])
        swap(&arr[*j], &arr[*j + 1]);

    (*j)++;
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
