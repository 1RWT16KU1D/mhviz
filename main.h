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
#define WIDTH 2500

#define HEIGHT_FACTOR 20
#define BAR_WIDTH (WIDTH / NELEMS)

typedef struct
{
    Rectangle rect;
    Color color;
    bool active;
} Bar;

// Functions
void visualize(void);
