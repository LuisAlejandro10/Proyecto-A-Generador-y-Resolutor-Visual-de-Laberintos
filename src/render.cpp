#include "render.h"
#include "raylib.h"
#include "../include/Globals.h"



render::render(int ancho, int alto, int filas, int columnas){
    this -> ancho = ancho;
    this -> alto = alto;
    this -> filas = filas;
    this -> columnas = columnas;

    this -> tamañodelacelda = alto/filas;

}

void render::dibujarcuadricula(){
    for (int fila = 0; fila <= filas; fila++){
        DrawLine(
            0,
            fila * tamañodelacelda,
            columnas * tamañodelacelda,
            fila * tamañodelacelda,
            BLACK
        );
    }

    for (int columna = 0; columna <= columnas;columna++){
        DrawLine(
            columna * tamañodelacelda,
            0,
            columna * tamañodelacelda,
            filas * tamañodelacelda,
            BLACK
        );
    }
}

void render::dibujarCelda(int fila, int columna, Color color){
    int x = columna * tamañodelacelda;
    int y = fila * tamañodelacelda;

    DrawRectangle(
        x + 1,
        y + 1, 
        tamañodelacelda - 2,
        tamañodelacelda - 2,
        color
    );
}

void render::dibujarLaberinto(){
    for(int fila = 0; fila < filas; fila++){
        for(int columna = 0; columna < columnas; columna++){
            int x = columna * tamañodelacelda;
            int y = fila * tamañodelacelda;

            if(grid[fila][columna].top)
                 DrawLineEx(
                    {(float)x, (float)y},
                    {(float)(x + tamañodelacelda), (float)y},
                    3,
                    BLACK
                );

            if (grid[fila][columna].right)
                 DrawLineEx(
                    {(float)(x + tamañodelacelda), (float)y},
                    {(float)(x + tamañodelacelda), (float)(y + tamañodelacelda)},
                    3,
                    BLACK
                );

            if (grid[fila][columna].bottom)
                 DrawLineEx(
                    {(float)x, (float)(y + tamañodelacelda)},
                    {(float)(x + tamañodelacelda), (float)(y + tamañodelacelda)},
                    3,
                    BLACK
                );

            if (grid[fila][columna].left)
                DrawLineEx(
                    {(float)x, (float)y},
                    {(float)x, (float)(y + tamañodelacelda)},
                    3,
                    BLACK
                );
        }
    }
}
void render::dibujarCamino(vector<pair<int,int>> camino)
{
    for(auto celda : camino)
    {
        int fila = celda.first;
        int columna = celda.second;

        int x = columna * tamañodelacelda;
        int y = fila * tamañodelacelda;

        DrawRectangle(
            x + 10,
            y + 10,
            tamañodelacelda - 20,
            tamañodelacelda - 20,
            BLUE
        );
    }
}