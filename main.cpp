#include "raylib.h"
#include "render.h"
#include <iostream>
#include <string.h>

int main(){
    
    const int anchodepantalla = 1720;
    const int altodepantalla = 1080;
    
    const int filas = 10;
    const int columnas = 10; 

    InitWindow(anchodepantalla, altodepantalla, "Generador y Resolutor Visual de Laberintos");
    SetTargetFPS(60);

    render render(anchodepantalla, altodepantalla, filas, columnas);

    while (!WindowShouldClose()) {
        BeginDrawing();

        ClearBackground(RAYWHITE);

        render.dibujarcuadricula();

        DrawText("Laberinto 10x10", 1500, 10, 30, BLACK); 

        EndDrawing();
    }

    CloseWindow();
    


    return 0;
}