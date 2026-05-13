#include "raylib.h"
#include "render.h"
#include "Globals.h"
#include "Maze.h"
#include "Graph.h"
#include "BFS.h"

#include <iostream>
#include <vector>
#include <utility>

using namespace std;

int main(){

    const int anchodepantalla = 600;
    const int altodepantalla = 600;

    const int filas = 10;
    const int columnas = 10;

    InitWindow(
        anchodepantalla,
        altodepantalla,
        "Generador y Resolutor Visual de Laberintos"
    );

    SetTargetFPS(60);

    render render(
        anchodepantalla,
        altodepantalla,
        filas,
        columnas
    );

    generar(0, 0);

    // abrir entrada y salida
    grid[0][0].top = false;
    grid[filas - 1][columnas - 1].bottom = false;

    // construir grafo
    auto grafo = construirGrafo();

    // BFS
    vector<pair<int,int>> explorados;

    auto camino = bfs(grafo, explorados);

    // VARIABLES DE ANIMACION
    int pasoExploracion = 0;
    int pasoCamino = 0;

    float tiempoExploracion = 0.0f;
    float tiempoCamino = 0.0f;

    float velocidadExploracion = 0.03f;
    float velocidadCamino = 0.08f;

    bool exploracionTerminada = false;

    while (!WindowShouldClose()) {

        if (IsKeyPressed(KEY_R)) {
        reiniciarGrid();
        generar(0, 0);

        grid[0][0].top = false;
        grid[filas - 1][columnas - 1].bottom = false;

        grafo = construirGrafo();

        explorados.clear();
        camino = bfs(grafo, explorados);

        pasoExploracion = 0;
        pasoCamino = 0;
        tiempoExploracion = 0.0f;
        tiempoCamino = 0.0f;
        exploracionTerminada = false;
    }

    if (IsKeyPressed(KEY_SPACE)) {
        pasoExploracion = 0;
        pasoCamino = 0;
        tiempoExploracion = 0.0f;
        tiempoCamino = 0.0f;
        exploracionTerminada = false;
    }

        float delta = GetFrameTime();

        // ANIMAR EXPLORACION
        if (!exploracionTerminada) {

            tiempoExploracion += delta;

            if (
                tiempoExploracion >= velocidadExploracion &&
                pasoExploracion < explorados.size()
            ) {

                pasoExploracion++;
                tiempoExploracion = 0.0f;
            }

            if (pasoExploracion >= explorados.size()) {
                exploracionTerminada = true;
            }
        }

        // ANIMAR CAMINO FINAL
        else {

            tiempoCamino += delta;

            if (
                tiempoCamino >= velocidadCamino &&
                pasoCamino < camino.size()
            ) {

                pasoCamino++;
                tiempoCamino = 0.0f;
            }
        }

        // EXPLORADOS PARCIALES
        vector<pair<int,int>> exploradosParcial(
            explorados.begin(),
            explorados.begin() + pasoExploracion
        );

        // CAMINO PARCIAL
        vector<pair<int,int>> caminoParcial(
            camino.begin(),
            camino.begin() + pasoCamino
        );

        BeginDrawing();

        ClearBackground(RAYWHITE);

        render.dibujarExplorados(exploradosParcial);
        render.dibujarCamino(caminoParcial);
        render.dibujarCelda(0, 0, GREEN);
        render.dibujarCelda(9, 9, RED);
        render.dibujarLaberinto();
        DrawText("R: Nuevo laberinto", 10, 10, 18, DARKGRAY);
        DrawText("SPACE: Repetir BFS", 10, 35, 18, DARKGRAY);

        EndDrawing();
    }

    CloseWindow();

    return 0;
}