#include "raylib.h"

#include "raylib.h"
#include <iostream>


int main()
{
    InitWindow(800, 450, "Mi primer proyecto con raylib y C++");

    SetTargetFPS(60);

    while (!WindowShouldClose())
    {
        BeginDrawing();

        ClearBackground(RAYWHITE);
        DrawText("Hola raylib no se que haccer en mi vida", 190, 200, 20, BLACK);

        EndDrawing();
    }

    CloseWindow();

    return 0;
}