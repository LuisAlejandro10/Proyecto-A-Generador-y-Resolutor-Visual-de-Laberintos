#include "../include/Maze.h"
#include "../include/Cell.h"
#include "../include/Globals.h"
#include <algorithm>//para mezclar los vecinos

//funcion para generar laberintos con recursividad
void generar(int i, int j) {

    grid[i][j].visited = true; //la marcamos como visitada

    vector<pair<int,int>> vecinos; //guardamos la coordenada

    //agregar vecino de arriba
    if (i > 0 && !grid[i-1][j].visited) {
        vecinos.push_back({i-1, j});
    }

    //agregar vecino de abajo
    if (i < filas - 1 && !grid[i+1][j].visited) {
        vecinos.push_back({i+1, j});
    }

    //agregar vecino de izquierda
    if (j > 0 && !grid[i][j-1].visited) {
        vecinos.push_back({i, j-1});
    }

    //agregar vecino de la derecha
    if (j < columnas - 1 && !grid[i][j+1].visited) {
        vecinos.push_back({i, j+1});
    }

    //mezclamos los vecinos
    shuffle(vecinos.begin(), vecinos.end(), g);

    while (!vecinos.empty()) {

        pair<int,int> siguiente = vecinos.back();
        vecinos.pop_back(); //solo quitamos uno

        //separamos las coordenadas
        int ni = siguiente.first;
        int nj = siguiente.second;

        if (!grid[ni][nj].visited) {

            // romper muro dependiendo de la direccion

            // derecha
            if (ni == i && nj == j + 1) {
                grid[i][j].right = false;
                grid[ni][nj].left = false;
            }

            // abajo
            if (ni == i+1 && nj == j) {
                grid[i][j].bottom = false;
                grid[ni][nj].top = false;
            }

            // arriba
            if (ni == i-1 && nj == j) {
                grid[i][j].top = false;
                grid[ni][nj].bottom = false;
            }

            // izquierda
            if (ni == i && nj == j-1) {
                grid[i][j].left = false;
                grid[ni][nj].right = false;
            }

            //recursividad :D
            generar(ni, nj);
        }
    }
}
