#ifndef SHAPE
#define SHAPE
#include"Shapeposition.h"
#include<raylib.h>
#include<vector>
using namespace std;

class Shape{
    private:
    int cellsize;
    Color colors[9];
    int rowoffset;
    int coloffset;
    public:
    Shapeposition position[4][4];
    Shape();
    int id;
    int rotationState;
    void DrawShape(int offsetX,int offsetY);
    void move(int rows,int columns);
    void rotateShape();
    vector<Shapeposition> GetCellPositions();
    void reverseRotation();
};

#endif