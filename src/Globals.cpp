#include "../include/Globals.h"
#include <ctime>

//vector<vector<Cell>> grid;

int filas = 10;
int columnas = 10;

vector<vector<Cell>> grid(filas, vector<Cell>(columnas));//crea vectores dentro de otro vector con n cantidad de filas y n cantidad de columnas


mt19937 g(time(0));
