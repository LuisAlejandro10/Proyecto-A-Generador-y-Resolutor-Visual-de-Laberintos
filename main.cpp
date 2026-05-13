#include "raylib.h"
#include "render.h"
#include "Globals.h"
#include "Maze.h"
#include <iostream>
#include <string.h>
#include "Graph.h"
#include "BFS.h"
#include <vector>



int main(){
    
    const int anchodepantalla = 600;
    const int altodepantalla = 600;
    
    const int filas = 10;
    const int columnas = 10; 

    InitWindow(anchodepantalla, altodepantalla, "Generador y Resolutor Visual de Laberintos");
    SetTargetFPS(60);

    render render(anchodepantalla, altodepantalla, filas, columnas);

    
    generar(0, 0);

    grid[0][0].top = false;
    grid[filas - 1][columnas - 1].bottom = false;
    //std::cout << "Laberinto generado correctamente" << std::endl;

    auto grafo = construirGrafo();
    auto camino = bfs(grafo);

    while (!WindowShouldClose()) {

        BeginDrawing();

        ClearBackground(RAYWHITE);

        render.dibujarCamino(camino);

        render.dibujarCelda(0, 0, RED);   // inicio
        render.dibujarCelda(9, 9, GREEN);     // final
        render.dibujarLaberinto();


        EndDrawing();
    }

    CloseWindow();
    


    return 0;
}