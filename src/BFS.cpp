#include "../include/BFS.h"
#include "../include/Globals.h"

#include <queue>
#include <iostream>

using namespace std;

vector<pair<int,int>> bfs(
    vector<vector<vector<pair<int,int>>>>& grafo
) {
    vector<vector<bool>> visitado(filas, vector<bool>(columnas, false));//revisar si ya fueron visitados
    vector<vector<pair<int,int>>> padre(filas, vector<pair<int,int>>(columnas, {-1,-1})); //recordar de donde vinimos
    //BFS
    queue<pair<int,int>> q; //agregamos a la cola

    q.push({0,0}); //guardamos el nodo inicial
    visitado[0][0] = true;

    while (!q.empty()) {

        pair<int,int> actual = q.front();
        q.pop();

        int i = actual.first;
        int j = actual.second;

        //recorrer vecinos del grafo
        for (auto vecino : grafo[i][j]) {

            int ni = vecino.first;
            int nj = vecino.second;

            if (!visitado[ni][nj]) {

                visitado[ni][nj] = true;
                padre[ni][nj] = {i, j};
                q.push({ni, nj});
            }
        }
    }

    //reconstruir camino
    vector<pair<int,int>> camino;

    int ci = filas - 1;
    int cj = columnas - 1;

    while (!(ci == 0 && cj == 0)) {

        if (padre[ci][cj].first == -1) {
            cout << "ERROR: no hay camino" << endl;
        break;
        }

        camino.push_back({ci, cj});

        pair<int,int> p = padre[ci][cj];
        ci = p.first;
        cj = p.second;
    }

    camino.push_back({0,0});
    return camino;
}
