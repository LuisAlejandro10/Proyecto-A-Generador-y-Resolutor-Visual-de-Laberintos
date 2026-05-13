#ifndef GLOBALS_H
#define GLOBALS_H

#include <vector>
#include <random>
#include "Cell.h"

using namespace std;

extern vector<vector<Cell>> grid;

extern int filas;
extern int columnas;

extern mt19937 g;

void reiniciarGrid(); //para reiniciar el grid 

#endif
