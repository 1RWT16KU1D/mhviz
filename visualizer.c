#include "main.h"

// Global initializations
static int *nums;
Rectangle rectangles[NELEMS];
Bar bars[NELEMS];
bool sorted = FALSE;
int highlightedIndices[2];

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
    for (int i = 0; i < NELEMS; i++)
    {
        bars[i].rect.height = HEIGHT_FACTOR * arr[i];
        bars[i].rect.x = BAR_WIDTH * i;
        bars[i].rect.y = HEIGHT - (HEIGHT_FACTOR * arr[i]);
        bars[i].color = WHITE;
    }

    if (highlightedIndices[0] >= 0 && highlightedIndices[0] < NELEMS)
        bars[highlightedIndices[0]].color = RED;
    if (highlightedIndices[1] >= 0 && highlightedIndices[1] < NELEMS)
        bars[highlightedIndices[1]].color = YELLOW;
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

    int i = 0, j = 0, k = 0;
    int minIdx = 0;
    highlightedIndices[0] = -1;
    highlightedIndices[1] = -1;
    initArray(NELEMS);

    initRectangleData();
    initBarData();

    InitWindow(WIDTH, HEIGHT, "mhviz - A Sorting Algorithm Visualizer");
    SetTargetFPS(FRAME_RATE_FAST);

    while (!WindowShouldClose())
    {   
        BeginDrawing();
            ClearBackground(BLACK);
            if (!isSorted(nums, NELEMS))
            {
                //bubbleStepSort(&i, &j, highlightedIndices, nums, NELEMS);
                selectionStepSort(&i, &j, highlightedIndices, &minIdx, nums, NELEMS);
                updateBarData(bars, nums);
            }
            else
            {
                if (k < NELEMS)
                {
                    bars[k].color = LIME;
                    k++;
                }
            }
            drawBars(NELEMS);
        EndDrawing();
    }
    CloseWindow();

    free(nums);
}
#pragma endregion
