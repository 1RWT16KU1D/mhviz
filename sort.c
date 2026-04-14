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

// Can swap every iteration
void bubbleStepSort(int *i, int *j, int highlightedIndices[], int arr[], int n)
{   
    if (*i >= n - 1)
        return;

    if (*j >= n - *i - 1)
    {
        (*i)++;
        *j = 0;
        return;
    }

    highlightedIndices[0] = *j;
    highlightedIndices[1] = *j + 1;

    if (arr[*j] > arr[*j + 1])
        swap(&arr[*j], &arr[*j + 1]);

    (*j)++;
}

// Swap only after reaching end of array
void selectionStepSort(int *i, int *j, int highlightedIndices[], int *minIdx, int arr[], int n)
{
    if (*i >= n - 1)
        return;

    if (*j <= *i)
    {
        *minIdx = *i;
        *j = *i + 1;
    }

    // After reaching the end, swap and reset for next outer loop
    if (*j >= n)
    {
        swap(&arr[*minIdx], &arr[*i]);
        (*i)++;
        *minIdx = *i;
        *j = *i + 1;
        return;
    }

    if (arr[*j] < arr[*minIdx])
        *minIdx = *j;

    highlightedIndices[0] = *j;
    highlightedIndices[1] = *minIdx;
    (*j)++;
}
