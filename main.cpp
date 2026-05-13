#include "raylib.h"
#include "render.h"
#include "Globals.h"
#include "Maze.h"
#include <iostream>
#include <string.h>

int main(){
    
    const int anchodepantalla = 800;
    const int altodepantalla = 600;
    
    const int filas = 10;
    const int columnas = 10; 

    InitWindow(anchodepantalla, altodepantalla, "Generador y Resolutor Visual de Laberintos");
    SetTargetFPS(60);

    render render(anchodepantalla, altodepantalla, filas, columnas);

    std::cout << "Filas: " << grid.size() << std::endl;
    std::cout << "Columnas: " << grid[0].size() << std::endl;
    generar(0, 0);
    //std::cout << "Laberinto generado correctamente" << std::endl;

    while (!WindowShouldClose()) {

        BeginDrawing();

        ClearBackground(RAYWHITE);

        
        render.dibujarCelda(0, 0, GREEN);   // inicio
        render.dibujarCelda(9, 9, RED);     // final
        render.dibujarLaberinto();


        EndDrawing();
    }

    CloseWindow();
    


    return 0;
}