#include "main.h"

static int *arr;
Bar bars[NELEMS];

static int *setArray(int arr[], int n)
{
    arr = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++)
        arr[i] = GetRandomValue(1, MAX_VALUE);
    return arr;
}

static inline void drawBar(int x, int y, int width, int height)
{
    DrawRectangle(x, y, width, height, WHITE);
    DrawRectangleLines(x, y, width, height, BLACK);
}

void drawBars(int n)
{
    for (int i = 0; i < n; i++)
    {
        drawBar(BAR_WIDTH * i, HEIGHT - (20 * arr[i]), BAR_WIDTH, 20 * arr[i]);
    }
}

void visualize(void)
{
    SetRandomSeed((unsigned int)time(NULL));
    arr = setArray(arr, NELEMS);
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