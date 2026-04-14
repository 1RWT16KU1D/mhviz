#pragma once

#include "raylib.h"
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

// For MY convenience
#define TRUE true
#define FALSE false

#define NELEMS 50
#define MAX_VALUE 50

#define HEIGHT ((20 * MAX_VALUE) + 250)
#define INITIAL_WIDTH 2500

// Because the extra space was annoying me
#if ((INITIAL_WIDTH % NELEMS) != 0)
#define WIDTH (INITIAL_WIDTH - (INITIAL_WIDTH % NELEMS))
#else
#define WIDTH INITIAL_WIDTH
#endif

#define HEIGHT_FACTOR 20
#define BAR_WIDTH (WIDTH / NELEMS)

typedef struct
{
    Rectangle rect;
    Color color;
    bool active;
} Bar;

// Sorting Algorithms
void swap(int *a, int *b);
bool isSorted(int arr[], int n);
void bubbleStepSort(int *i, int *j, int swappedIndices[], int arr[], int n);
void selectionStepSort(int *i, int *j, int swappedIndices[], int *minIdx, int arr[], int n);

// Functions
void visualize(void);
