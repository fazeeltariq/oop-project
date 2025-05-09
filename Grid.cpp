#include"Grid.h"
#include<iostream>

Grid::Grid():cellsize(32),rows(20),columns(10),offsetX(20),offsetY(8)
{
    for (int i=0;i<20;i++){
        for (int j=0;j<10;j++)
        {
            grid[i][j]=0;
        }   
    }
    colors[0]=DARKGRAY;

        // ALL SHAPES:
    colors[1]=SKYBLUE;   // I block 
    colors[2]=YELLOW;    // O block 
    colors[3]=PURPLE;    // T block 
    colors[4]=LIME;      // S block 
    colors[5]=RED;       // Z block 
    colors[6]=BLUE;      // J block 
    colors[7]=ORANGE;    // L block 
    colors[8]=WHITE;     // new shape introduced White Color
}
void Grid::DrawGrid() 
{
    for (int i=0;i<rows;i++)
     {
        for (int j=0;j<columns;j++) {
                int colortype=grid[i][j];
                DrawRectangle(offsetX+(j*cellsize)+1,offsetY+(i*cellsize)+1,cellsize-1,cellsize-1,colors[colortype]);
            }
        }
    }

bool Grid::isRowfull(int row){
    for (int i=0;i<columns;i++)
    {
        if(grid[row][i]==0){
            return false;
        }
    }
    return true;
}

bool Grid::isCellvacant(int row, int column)
{
    if(grid[row][column]==0)
    {
        return true;
    }
    return false;
}

void Grid::moveRowDown(int row,int numRows)
{
    for (int i=0;i<columns;i++)
    {
        grid[row+numRows][i]=grid[row][i];
        grid[row][i]=0;
    }
    
}
void Grid::clearRow(int row)
{
    for (int i=0;i<columns;i++)
    {
    grid[row][i]=0;
    }
}

int Grid::ClearFullRows(){
    int completed=0;
    for (int i=rows-1;i>=0;i--)
    {
        if(isRowfull(i)){
            clearRow(i);
            completed++;
        }
        else if(completed>0){
            moveRowDown(i,completed);
        }
    }
    return completed;
    
}

    int Grid::getcellsize()const{
        return cellsize;
    }
    int Grid::getrows()const{
        return rows;
    }
    int Grid::getcolumns()const{
        return columns;
    }
    int Grid::getoffsetX()const{
        return offsetX;
    }
    int Grid::getoffsetY()const{
        return offsetY;
    }
    int (*Grid::getGrid())[10] {
        return grid;
    }
    void Grid::initialize()
    {
        for (int i=0;i<rows;i++)
        {
            for (int j=0;j<columns;j++)
            {
                grid[i][j]=0;
            }
            
        }
    }
    bool Grid::isShapeOutside(int i, int j) {
        if (i  >= 0 && i < rows && j >= 0 && j < columns)
            return false;
        else
            return true;
    }
    
