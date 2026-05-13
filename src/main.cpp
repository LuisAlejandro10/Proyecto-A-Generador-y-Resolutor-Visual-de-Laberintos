#include <iostream>
#include "../include/Cell.h" //estructura
#include "../include/Maze.h" //generador
#include "../include/Globals.h" //variables globales
#include "../include/BFS.h" //Busqueda en anchura
#include "../include/Graph.h"//conversion a grafo
#include <vector> //libreria para guardar las filas, columnas y vecinos

using namespace std;

int main()
{

    //crear grid
    for (int i = 0; i < filas; i++) {   //recorre filas
        vector<Cell> fila;
        for (int j = 0; j < columnas; j++){  //recorre columnas
            Cell c(i, j);         //instanciamos con los parametros
            fila.push_back(c);   //guardamos la instancia
        }
        grid.push_back(fila); // guardamos la fila
    }

    //crear laberinto
    generar(0,0);

    grid[0][0].top = false; // entrada
    grid[filas-1][columnas-1].bottom = false; // salida

    //crear grafo
    vector<vector<vector<pair<int,int>>>> grafo = construirGrafo();

    //resolver con bfs
    vector<pair<int,int>> camino = bfs(grafo);

    //marcar el camino con una matriz
    vector<vector<bool>> ruta(filas, vector<bool>(columnas, false));

    //marcar ruta
    for (auto c : camino) {
        cout << "(" << c.first << "," << c.second << ") ";
    }

    for (auto c : camino) {
        ruta[c.first][c.second] = true;
    }

    cout << endl << endl;

    //mostrar el laberinto
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

            if (ruta[i][j])
                cout << " * ";
            else
                cout << "   ";
        }

        cout << "|" << endl;

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
