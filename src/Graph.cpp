#include "../include/Graph.h"
#include "../include/Globals.h"
#include "../include/Cell.h"

using namespace std;

//funcion para construir el grafo
vector<vector<vector<pair<int,int>>>> construirGrafo() {

    //crear el grafo usando coordenadas
    vector<vector<vector<pair<int,int>>>> grafo;

    grafo.resize(filas, vector<vector<pair<int,int>>>(columnas));

    //recorrer el grid
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {

            //derecha
            if (!grid[i][j].right && j + 1 < columnas) {
                grafo[i][j].push_back({i, j+1});
            }

            //izquierda
            if (!grid[i][j].left && j - 1 >= 0) {
                grafo[i][j].push_back({i, j-1});
            }

            //arriba
            if (!grid[i][j].top && i - 1 >= 0) {
                grafo[i][j].push_back({i-1, j});
            }

            //abajo
            if (!grid[i][j].bottom && i + 1 < filas) {
                grafo[i][j].push_back({i+1, j});
            }
        }
    }

    return grafo;
}
