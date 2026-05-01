#include <iostream>
#include "../include/Cell.h" //estructura
#include <vector> //libreria para guardar las filas, columnas y vecinos
#include <ctime> //libreria de tiempo
#include <algorithm>//para mezclar los vecinos
#include <random>

using namespace std;

vector<vector<Cell>> grid; // se define a cuadricula
int filas = 10;   //se define el tamano de la matriz
int columnas = 10;
mt19937 g(time(0));

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

int main()
{

    for (int i = 0; i < filas; i++) {   //recorre filas
        vector<Cell> fila;
        for (int j = 0; j < columnas; j++){  //recorre columnas
            Cell c(i, j);         //instanciamos con los parametros
            fila.push_back(c);   //guardamos la instancia

        }
        grid.push_back(fila); // guardamos la fila
    }

    //llamamos la funcion en coord (0, 0)
    generar(0,0);

    grid[0][0].top = false; // entrada

    grid[filas-1][columnas-1].bottom = false; // salida

    //mostrar el laberinto de manera temporal
    for (int j = 0; j < columnas; j++) {
    cout << "+---";
    }
    cout << "+" << endl;

    for (int i = 0; i < filas; i++) {

    for (int j = 0; j < columnas; j++) {

        if (grid[i][j].left)
            cout << "|";
        else
            cout << " ";

        cout << "   "; // espacio de la celda
    }

    cout << "|" << endl; // pared derecha final
    for (int j = 0; j < columnas; j++) {

    cout << "+";

    if (grid[i][j].bottom)
        cout << "---";
    else
        cout << "   ";
    }

    cout << "+" << endl;
    }

    return 0;
}
