#ifndef RENDERER_H
#define RENDERER_H

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
};

#endif