#include"Shape.h"
#include<vector>
using namespace std;

Shape::Shape(){
    cellsize=32;
    rotationState=0;
    id=0;
    rowoffset=0;
    coloffset=0;
    colors[0]=DARKGRAY; // for blank block
    colors[1]=SKYBLUE;   //Color of I block 
    colors[2]=YELLOW;    //Color of O block Yellow
    colors[3]=PURPLE;    //Color of T block Purple
    colors[4]=LIME;      //Color of S block Green
    colors[5]=RED;       //Color of Z block Red
    colors[6]=BLUE;      //Color of J block Blue
    colors[7]=ORANGE;    //Color of L block Orange
    colors[8]=WHITE;     // new shape introcduced for harder level:
}

void Shape::DrawShape(int offsetX=0,int offsetY=0) {
    vector<Shapeposition> position = GetCellPositions();
    for (int i=0;i<4;i++) {
        int x=20+position[i].column*cellsize;
        int y=8+position[i].row*cellsize;
        DrawRectangle(x+1+offsetX,y+1+offsetY,cellsize-1,cellsize-1,colors[id]);
    }
}
void Shape::move(int rows,int columns)
{
    rowoffset+=rows;
    coloffset+=columns;
}
void Shape::rotateShape()
{
    rotationState=(rotationState+1) % 4;
}
vector<Shapeposition> Shape::GetCellPositions()
{
    vector<Shapeposition> moveshapes;
    for (int i=0;i<4;i++) {
        Shapeposition p;
        p.row=position[rotationState][i].row + rowoffset;
        p.column=position[rotationState][i].column + coloffset;
        moveshapes.push_back(p);
    }
    return moveshapes;
}
void Shape::reverseRotation(){
    rotationState = (rotationState + 3) % 4;
}