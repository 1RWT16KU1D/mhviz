#include "main.h"

static int *arr;

static int *setArray(int arr[], int n)
{
    arr = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++)
        arr[i] = rand() % 40;
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
        drawBar(50 * i, HEIGHT - (20 * arr[i]), 50, 20 * arr[i]);
    }
}

void visualize(void)
{
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