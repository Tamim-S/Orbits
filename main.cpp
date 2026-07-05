/*
|| Orbits
|| Creator: Tamim S
|| Version 1.1 (July 3, 2026) - C++, Raylib
|| Overview: Simple program that demonstrates planetary orbits
*/

// Includes and defines
#include "raylib.h"
#include <math.h>
#include <string>
#include <vector>
#include <iostream>

using namespace std;

int main() {
    // Raylib window initialization
    InitWindow(800, 800, "Orbits");
    SetTargetFPS(60);

    // Main loop
    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(RAYWHITE);

        DrawCircle(400, 400, 50.0f, BLUE);

        EndDrawing();
    }

    CloseWindow;
    return 0;
}
