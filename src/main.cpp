#include <iostream>
#include "../include/Cell.h" //estructura
#include <vector> //libreria para guardar las filas, columnas y vecinos
#include <ctime> //libreria de tiempo
#include <algorithm>//para mezclar los vecinos
#include <random>// randomizar el laberinto
#include <queue> //libreria de cola

using namespace std;

vector<vector<Cell>> grid; // se define a cuadricula
int filas = 10;   //se define el tamano de la matriz
int columnas = 10;
mt19937 g(time(0)); //randomizador
vector<vector<vector<pair<int,int>>>> grafo;// crear el grafo usando coordenadas

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

    vector<vector<bool>> visitado(filas, vector<bool>(columnas, false));//revisar si ya fueron visitados
    vector<vector<pair<int,int>>> padre(filas, vector<pair<int,int>>(columnas, {-1,-1})); //recordar de donde vinimos

    //crear grid
    for (int i = 0; i < filas; i++) {   //recorre filas
        vector<Cell> fila;
        for (int j = 0; j < columnas; j++){  //recorre columnas
            Cell c(i, j);         //instanciamos con los parametros
            fila.push_back(c);   //guardamos la instancia
        }
        grid.push_back(fila); // guardamos la fila
    }

    grafo.resize(filas, vector<vector<pair<int,int>>>(columnas));

    //llamamos la funcion en coord (0, 0)
    generar(0,0);

    grid[0][0].top = false; // entrada
    grid[filas-1][columnas-1].bottom = false; // salida

    //construir grafo
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {

            //derecha
            if (!grid[i][j].right && j + 1 < columnas) {
                grafo[i][j].push_back({i, j+1});
            }

            // izquierda
            if (!grid[i][j].left && j - 1 >= 0) {
                grafo[i][j].push_back({i, j-1});
            }

            // arriba
            if (!grid[i][j].top && i - 1 >= 0) {
                grafo[i][j].push_back({i-1, j});
            }

            // abajo
            if (!grid[i][j].bottom && i + 1 < filas) {
                grafo[i][j].push_back({i+1, j});
            }
        }
    }

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

    vector<vector<bool>> ruta(filas, vector<bool>(columnas, false)); //marcar el camino con una matriz

    //imprimir camino
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
