#ifndef GRID
#define GRID
#include<iostream>
#include<raylib.h>
using namespace std;


class Grid{
    private:
    const int cellsize;
    const int rows;
    const int columns;
    const int offsetX;
    const int offsetY;
    Color colors[9];
    public:
    int grid[20][10];
    Grid();
    bool isShapeOutside(int row,int column);
    void DrawGrid();
    bool isCellvacant(int row,int column);
    bool isRowfull(int row);
    void moveRowDown(int row,int numRows);
    void clearRow(int row);
    int ClearFullRows();
    int getcellsize() const;
    int getrows()const;
    int getcolumns()const;
    int getoffsetX()const;
    int getoffsetY()const;
    int (*getGrid())[10];
    void initialize();
};

#endif