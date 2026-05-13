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
            int x = fila * tamañodelacelda;
            int y = columna * tamañodelacelda;

            if(grid[fila][columna].top)
                DrawLine(x, y, x + tamañodelacelda, y, BLACK);

            if (grid[fila][columna].right)
                DrawLine(x + tamañodelacelda, y, x + tamañodelacelda, y + tamañodelacelda, BLACK);

            if (grid[fila][columna].bottom)
                DrawLine(x, y + tamañodelacelda, x + tamañodelacelda, y + tamañodelacelda, BLACK);

            if (grid[fila][columna].left)
                DrawLine(x, y, x, y + tamañodelacelda, BLACK);
        }
    }
}