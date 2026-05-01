#ifndef CELL_H
#define CELL_H

struct Cell {
    int row; //filas
    int col; //columnas

    bool top; //arriba
    bool bottom; //abajo
    bool left; //izquierda
    bool right; //derecha

    bool visited; //para saber si ya fue visitado

    Cell(int r, int c) { //constructor
        row = r;
        col = c;

        top = true; //las inicialicamos con true como celdas completas
        bottom = true;
        left = true;
        right = true;

        visited = false; //le asignamos valor por default
    }
};

#endif
