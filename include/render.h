#ifndef RENDERER_H
#define RENDERER_H

class Renderer {
private:
    int ancho;
    int alto;
    int filas;
    int columnas;
    int tamañodelacelda;

public:
    Renderer(int ancho, int alto, int filas, int columnas);

    void drawGrid();
};

#endif