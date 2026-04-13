#include "main.h"

// Global initializations
static int *arr;
Rectangle rectangles[NELEMS];
Bar bars[NELEMS];

#pragma region Data Initialization
static int *initArray(int arr[], int n)
{
    arr = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++)
        arr[i] = GetRandomValue(1, MAX_VALUE);
    return arr;
}

static void initRectangleData(void)
{
    for (int i = 0; i < NELEMS; i++)
    {
        rectangles[i].height = HEIGHT_FACTOR * arr[i];
        rectangles[i].width = BAR_WIDTH;
        rectangles[i].x = BAR_WIDTH * i;
        rectangles[i].y = HEIGHT - (HEIGHT_FACTOR * arr[i]);
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
    arr = initArray(arr, NELEMS);
    initRectangleData();
    initBarData();
    InitWindow(WIDTH, HEIGHT, "mhviz - A Sorting Algorithm Visualizer");
    SetTargetFPS(60);
    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(BLACK);
        drawBars(NELEMS);
        DrawFPS(10, 10);
        EndDrawing();
    }
    CloseWindow();
}
#pragma endregion