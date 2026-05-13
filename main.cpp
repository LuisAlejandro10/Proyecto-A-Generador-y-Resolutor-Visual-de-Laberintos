#include "raylib.h"
#include "render.h"
#include <iostream>
#include <string.h>

int main(){
    
    const int anchodepantalla = 1520;
    const int altodepantalla = 1080;
    
    const int filas = 10;
    const int columnas = 10; 

    InitWindow(anchodepantalla, altodepantalla, "Generador y Resolutor Visual de Laberintos");
    SetTargetFPS(60);

    render render(anchodepantalla, altodepantalla, filas, columnas);

    while (!WindowShouldClose()) {

        BeginDrawing();

        ClearBackground(RAYWHITE);
        
        render.dibujarCelda(0, 0, GREEN);   // inicio
        render.dibujarCelda(9, 9, RED);     // final
        render.dibujarcuadricula();

        DrawText("Laberinto 10x10", 1200, 10, 30, BLACK); 

        EndDrawing();
    }

    CloseWindow();
    


    return 0;
}