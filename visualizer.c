#include "main.h"
#include <stdio.h>

// Global initializations
static int *nums;
Rectangle rectangles[NELEMS];
Bar bars[NELEMS];
bool sorted = FALSE;
int swappedIndices[2];

#pragma region Data Initialization
static void initArray(int n)
{
    nums = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++)
        nums[i] = GetRandomValue(1, MAX_VALUE);
}

static void initRectangleData(void)
{
    for (int i = 0; i < NELEMS; i++)
    {
        rectangles[i].height = HEIGHT_FACTOR * nums[i];
        rectangles[i].width = BAR_WIDTH;
        rectangles[i].x = BAR_WIDTH * i;
        rectangles[i].y = HEIGHT - (HEIGHT_FACTOR * nums[i]);
    }
}

static void initBarData(void)
{
    for (int i = 0; i < NELEMS; i++)
    {
        bars[i].rect = rectangles[i];
        bars[i].color = WHITE;
        bars[i].active = TRUE;
    }
}

static void updateBarData(Bar bars[], int arr[])
{
    fSwap(&bars[swappedIndices[0]].rect.height, &bars[swappedIndices[1]].rect.height);
    fSwap(&bars[swappedIndices[0]].rect.x, &bars[swappedIndices[1]].rect.x);
    bars[swappedIndices[0]].color = GREEN;
    bars[swappedIndices[1]].color = RED;
}

#pragma endregion

#pragma region Drawing Logic
static inline void drawBar(Rectangle rect, Color color)
{
    DrawRectangleRec(rect, color);
    DrawRectangleLines(rect.x, rect.y, rect.width, rect.height, BLACK);
}

void drawBars(int n)
{
    for (int i = 0; i < n; i++)
        drawBar(bars[i].rect, bars[i].color);
}

void visualize(void)
{
    SetRandomSeed((unsigned int)time(NULL));

    int i = 0, j = 0;
    initArray(NELEMS);

    initRectangleData();
    initBarData();

    InitWindow(WIDTH, HEIGHT, "mhviz - A Sorting Algorithm Visualizer");
    SetTargetFPS(120);

    while (!WindowShouldClose())
    {   
        BeginDrawing();
            if (!isSorted(nums, NELEMS))
            {
                bubbleStepSort(&i, &j, swappedIndices, nums, NELEMS);
                updateBarData(bars, nums);
                ClearBackground(BLACK);
                drawBars(NELEMS);
            }
        EndDrawing();
    }
    CloseWindow();

    for (i = 0; i < NELEMS; i++)
        printf("%d ", nums[i]);
    printf("\n");
    free(nums);
}
#pragma endregion