#include "raylib.h"
#include "render.h"
#include <iostream>
#include <string.h>

int main(){
    
    const int anchodepantalla = 1920;
    const int altodepantalla = 180;
    
    const int filas = 10;
    const int columnas = 10; 

    InitWindow(anchodepantalla, altodepantalla, "Generador y Resolutor Visual de Laberintos");
    SetTargetFPS(60);

    render render(anchodepantalla, altodepantalla, filas, columnas);

    while (!WindowShouldClose()) {
        BeginDrawing();

        ClearBackground(RAYWHITE);

        render.dibujarcuadricula();

        DrawText("Laberinto 10x10", 620, 30, 20, BLACK);

        EndDrawing();
    }

    CloseWindow();
    

    return 0;
}