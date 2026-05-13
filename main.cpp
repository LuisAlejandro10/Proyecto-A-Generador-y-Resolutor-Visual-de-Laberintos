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

int main() {

    const int anchodepantalla = 600;
    const int altodepantalla = 600;

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

    // Generar laberinto inicial
    reiniciarGrid();
    generar(0, 0);

    // Entrada y salida
    grid[0][0].top = false;
    grid[filas - 1][columnas - 1].bottom = false;

    // Construir grafo y resolver con BFS
    auto grafo = construirGrafo();

    vector<pair<int, int>> explorados;
    vector<pair<int, int>> camino = bfs(grafo, explorados);

    // Variables de animación
    int pasoExploracion = 0;
    int pasoCamino = 0;

    float tiempoExploracion = 0.0f;
    float tiempoCamino = 0.0f;

    float velocidadExploracion = 0.03f;
    float velocidadCamino = 0.08f;

    bool exploracionTerminada = false;

    while (!WindowShouldClose()) {

        float delta = GetFrameTime();

        // Tecla R: generar nuevo laberinto
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

        // Tecla ESPACIO: repetir animación BFS
        if (IsKeyPressed(KEY_SPACE)) {

            pasoExploracion = 0;
            pasoCamino = 0;

            tiempoExploracion = 0.0f;
            tiempoCamino = 0.0f;

            exploracionTerminada = false;
        }

        // Animar exploración BFS
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

        // Animar camino final
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

        vector<pair<int, int>> exploradosParcial(
            explorados.begin(),
            explorados.begin() + pasoExploracion
        );

        vector<pair<int, int>> caminoParcial(
            camino.begin(),
            camino.begin() + pasoCamino
        );

        BeginDrawing();

        ClearBackground(RAYWHITE);

        render.dibujarExplorados(exploradosParcial);
        render.dibujarCamino(caminoParcial);

        render.dibujarCelda(0, 0, GREEN);
        render.dibujarCelda(filas - 1, columnas - 1, RED);

        render.dibujarLaberinto();

        DrawText("R: Nuevo laberinto", 10, 10, 18, DARKGRAY);
        DrawText("SPACE: Repetir BFS", 10, 35, 18, DARKGRAY);

        EndDrawing();
    }

    CloseWindow();

    return 0;
}