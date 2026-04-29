#ifndef CELL_H
#define CELL_H

struct Cell {
    int row;
    int col;

    bool top;
    bool bottom;
    bool left;
    bool right;

    bool visited;

    Cell(int r, int c) {
        row = r;
        col = c;

        top = true;
        bottom = true;
        left = true;
        right = true;

        visited = false;
    }
};

#endif
