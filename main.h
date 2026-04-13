#pragma once

#include "raylib.h"
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

#define NELEMS 100
#define MAX_VALUE 50

#define HEIGHT ((20 * MAX_VALUE) + 250)
#define WIDTH 2500

#define BAR_WIDTH (WIDTH / NELEMS)

typedef struct
{
    Rectangle rect;
    Color color;
    bool active;
} Bar;

// Functions
void visualize(void);
