/*
|| Orbits
|| Creator: Tamim Saleem
|| Version 1.2 (July 5, 2026) - C++, Raylib
|| Overview: Simple program that demonstrates planetary orbits
*/

// Includes and defines
#include "raylib.h"
#include <math.h>
#include <string>
#include <vector>
#include <iostream>

using namespace std;

class Body {
public:
    float mass, x, y, vx, vy, ax, ay;
};

Body sun;    // global
Body p;
const float G = 0.667;

void initialize(Body& sun) {
    sun.mass = 100;
    sun.x = 400;
    sun.y = 400;
    sun.vx = 0;
    sun.vy = 0;
    sun.ax = 0;
    sun.ay = 0;
}

void initialize2(Body& p) {
    p.mass = 10;
    p.x = 400;
    p.y = 500;
    p.vx = 2;
    p.vy = 1;
    p.ax = 0;
    p.ay = 0;
}

int main() {
    // Raylib window initialization
    InitWindow(800, 800, "Orbits");
    SetTargetFPS(60);

    initialize(sun);
    initialize2(p);

    // Main loop
    while (!WindowShouldClose()) {
        // Compute gravitational acceleration
        // x and y distance between planet and sun
        float dx = sun.x - p.x;
        float dy = sun.y - p.y;

		// distance using dx and dy
        float distance = sqrt(dx * dx + dy * dy);

        // Orbital velocity -> float orbitalVelocity = sqrt(G * sun.mass / distance); [apply whenever desired]

        if ((dx * dx + dy * dy) > 0.0001f) {
            // gravity = GMm / r^2
            float force = G * sun.mass * p.mass / (dx * dx + dy * dy);

			// acceleration = force / mass
            float directionX = dx / distance;
            float directionY = dy / distance;

			// acceleration in x and y directions
            p.ax = force * directionX;
            p.ay = force * directionY;
        }
        
        // Update planet velocity
        p.vx += p.ax;
        p.vy += p.ay;

        // Update planet position
        p.x += p.vx;
        p.y += p.vy;

        BeginDrawing();
        ClearBackground(BLACK);

        DrawCircle(sun.x, sun.y, 30.0f, YELLOW);
        DrawCircle(p.x, p.y, 15.0f, BLUE);


        EndDrawing();
    }

    CloseWindow;
    return 0;
}
