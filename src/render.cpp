#include "render.h"
#include "raylib.h"




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


