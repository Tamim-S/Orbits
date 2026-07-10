/*
|| Orbits
|| Creator: Tamim Saleem
|| Version 1.3 (July 10, 2026) - C++, Raylib
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
vector<Vector2> trail;
const float G = 6.67;

void initialize(Body& sun) {
    sun.mass = 50;
    sun.x = 400;
    sun.y = 400;
    sun.vx = 0;
    sun.vy = 0;
    sun.ax = 0;
    sun.ay = 0;
}

void initialize2(Body& p) {
    p.mass = 1;
    p.x = 400;
    p.y = 500;
    p.vx = 2;
    p.vy = 0;
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

            // unit vectors
            float directionX = dx / distance;
            float directionY = dy / distance;

			// acceleration in x and y directions (magnitude times direction unit vector)
            p.ax = (force / p.mass) * directionX;
            p.ay = (force / p.mass) * directionY;
        }
        
        // Update planet velocity
        p.vx += p.ax;
        p.vy += p.ay;

        // Update planet position
        p.x += p.vx;
        p.y += p.vy;

        // Drawing trails
        // blue planet trail

        trail.push_back({p.x, p.y});

        for (int i = 0; i < trail.size(); i++) {
            DrawCircleV(trail[i], 2.0f, BLUE);
        }

        // Drawing vectors
        // velocity
        DrawLineEx({p.x, p.y}, {p.x + p.vx * 15, p.y + p.vy * 15}, 3.0f, GREEN);

		// acceleration
        DrawLineEx({p.x, p.y}, {p.x + p.ax * 1500, p.y + p.ay * 1500}, 3.0f, RED);

        // UI
        // escape text
		DrawText("Press ESC to exit", 10, 10, 20, WHITE);

        BeginDrawing();
        ClearBackground(BLACK);

        DrawCircle(sun.x, sun.y, 25.0f, YELLOW);
        DrawCircle(p.x, p.y, 12.0f, BLUE);


        EndDrawing();
    }

    CloseWindow;
    return 0;
}
