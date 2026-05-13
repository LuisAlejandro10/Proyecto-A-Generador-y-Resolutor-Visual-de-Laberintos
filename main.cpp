#include "raylib.h"
#include "render.h"
#include "Globals.h"
#include "Maze.h"
#include <iostream>
#include <string.h>
#include "Graph.h"
#include "BFS.h"
#include <vector>
#include <utility>
#include <algorithm>



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
    reverse(camino.begin(), camino.end());

    int pasoAnimacion = 0;
    float tiempoAcumulado = 0.0f;
    float velocidadAnimacion = 0.08f;

    int pasoExploracion = 0;
    int pasoCamino = 0;

    float tiempoExploracion = 0.0f;
    float tiempoCamino = 0.0f;

    float velocidadExploracion = 0.03f;
    float velocidadCamino = 0.08f;

    bool exploracionTerminada = false;

    while (!WindowShouldClose()) {

        float delta = GetFrameTime();

        if (!exploracionTerminada) {
            tiempoExploracion += delta;

        if (tiempoExploracion >= velocidadExploracion && pasoExploracion < explorados.size()) {
            pasoExploracion++;
            tiempoExploracion = 0.0f;
        }

        if (pasoExploracion >= explorados.size()) {
        exploracionTerminada = true;
        }
        }
    else {
        tiempoCamino += delta;

    if (tiempoCamino >= velocidadCamino && pasoCamino < camino.size()) {
        pasoCamino++;
        tiempoCamino = 0.0f;
    }
    }

        tiempoAcumulado += GetFrameTime();

        if (tiempoAcumulado >= velocidadAnimacion && pasoAnimacion < camino.size()) {
            pasoAnimacion++;
            tiempoAcumulado = 0.0f;
        }

        vector<pair<int,int>> exploradosParcial(
        explorados.begin(),
        explorados.begin() + pasoExploracion
        );

        
        vector<pair<int,int>> caminoParcial(
            camino.begin(),
            camino.begin() + pasoAnimacion
        );

        BeginDrawing();

        ClearBackground(RAYWHITE);

        render.dibujarExplorados(exploradosParcial);
        render.dibujarCamino(caminoParcial);

        render.dibujarCelda(0, 0, GREEN);   // inicio
        render.dibujarCelda(9, 9, RED);     // final
        render.dibujarLaberinto();


        EndDrawing();
    }

    CloseWindow();
    


    return 0;
}