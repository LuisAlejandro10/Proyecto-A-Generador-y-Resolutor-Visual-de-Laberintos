#ifndef RENDERER_H
#define RENDERER_H
#include "raylib.h"



class render{
private:
    int ancho;
    int alto;
    int filas;
    int columnas;
    int tamañodelacelda;

public:
    render(int ancho, int alto, int filas, int columnas);

    void dibujarcuadricula();
    void dibujarCelda(int fila, int columna, Color color);
    void dibujarMuro(int x1, int y1, int x2, int y2){
          DrawLine(x1, y1, x2, y2, BLACK);
    }
    void dibujarLaberinto(Maze& maze);
    
};

#endif

