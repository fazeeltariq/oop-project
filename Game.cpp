#include "Game.h"
#include "AllShapes.cpp"
#include <cstdlib>  
#include <ctime>
#include<vector>
using namespace std;

Game::Game(int level) {
    srand(time(0));
    gameover=false;
    shape[0]=new IShape();
    shape[1]=new JShape();
    shape[2]=new LShape();
    shape[3]=new OShape();
    shape[4]=new SShape();
    shape[5]=new TShape();
    shape[6]=new ZShape();
    shape[7]=new UShape();
    this->level=level;
    if(level==1){
    for (int i = 0; i < 7; i++) {
        shapeUsed[i] = false;
    }
}
else if(level==2){
    for (int i = 0; i < 8; i++) {
        shapeUsed[i] = false;
    } 
}
    shapecount=0;
    currentShape=*getRandomShape();
    nextShape=*getRandomShape();
    score=0;
    InitAudioDevice();
    music=LoadMusicStream("Sounds/music.mp3");
    PlayMusicStream(music);
    roatate=LoadSound("Sounds/rotate.mp3");
    clearsound=LoadSound("Sounds/clear.mp3");
}

void Game::updateScore(int lines,int movedownpoints){
    if(level==1){
    if(lines==1){
        score+=50;
    }
    else if(lines==2){
        score+=150;
    }
    else if(lines==3){
        score+=250;
    }
    else{
        score+=movedownpoints;
    }
    }
    else if(level==2){
        if(lines==1){
            score+=30;
        }
        else if(lines==2){
            score+=80;
        }
        else if(lines==3){
            score+=170;
        }
        else{
            score+=movedownpoints;
        }  
    }
}

Game::~Game()
{
    for (int i = 0; i < 8; i++) {
        delete shape[i];
    }
    CloseAudioDevice();
    UnloadMusicStream(music);
    UnloadSound(roatate);
    UnloadSound(clearsound);
}
Shape* Game::getRandomShape() {
    if(level==1){
    if (shapecount>=7) {
        for (int i=0;i<7;i++) {
            shapeUsed[i]=false;
        }
        shapecount=0;
    }
    int index;
    do {
    index = rand() % 7;
    } while (shapeUsed[index]);

    shapeUsed[index]=true;
    shapecount++;
    return shape[index];
    }
    else if(level==2){
        if (shapecount>=8) {
            for (int i=0;i<8;i++) {
                shapeUsed[i]=false;
            }
            shapecount=0;
        }
        int newindex;
        do {
        newindex = rand() % 8;
        } while (shapeUsed[newindex]);
        shapeUsed[newindex] = true;
        shapecount++;
        return shape[newindex];
    }
    else{
        return nullptr;
    }
}
void Game::DrawGame(){
    if(level==1){
    grid.DrawGrid();
    currentShape.DrawShape(0,0);
    if(nextShape.id==1){
        nextShape.DrawShape(346,404); 
    }
    else if(nextShape.id==2){
        nextShape.DrawShape(346,396);
    }
    else if(nextShape.id==4){
        nextShape.DrawShape(356,387);
    }
    else
    nextShape.DrawShape(360,395);
    }
    else if(level==2){
        grid.DrawGrid();
        currentShape.DrawShape(0,0);
        if(nextShape.id==1){
            nextShape.DrawShape(346,404); 
        }
        else if(nextShape.id==2){
            nextShape.DrawShape(346,396);
        }
        else if(nextShape.id==4){
            nextShape.DrawShape(356,387);
        }
        else
        nextShape.DrawShape(360,395);
        }
}

void Game::MoveShapes()
{
   int key=GetKeyPressed();
   if(gameover && key!=0){
    gameover=false;
    reset();
   }
    if(level==1){
    if(key==KEY_RIGHT){
        if(!gameover){
        currentShape.move(0,1);
        if(isShapeOutside() || blockAdjust()==false){
            currentShape.move(0,-1);
        }
    }
}
    else if(key==KEY_LEFT){
        if(!gameover){
        currentShape.move(0,-1);
        if(isShapeOutside() || blockAdjust()==false){
            currentShape.move(0,1);
        }
    }
    }
    else if(key==KEY_UP){
        if(!gameover){
        currentShape.rotateShape();
        if(isShapeOutside() || blockAdjust()==false){
            currentShape.reverseRotation();
        }
        else{
            PlaySound(roatate);
        }
    }
}
    else if(key==KEY_DOWN){
        if(!gameover){
        currentShape.move(1,0);
        if(isShapeOutside() || blockAdjust()==false){
            currentShape.move(-1,0);
            updateScore(0,1);
            score+=1;
            LockShape();
        }
    }
    }
    }
    else if(level==2){
        if(key==KEY_RIGHT){
            if(!gameover){
            currentShape.move(0,1);
            if(isShapeOutside() || blockAdjust()==false){
                currentShape.move(0,-1);
            }
        }
    }
        else if(key==KEY_LEFT){
            if(!gameover){
            currentShape.move(0,-1);
            if(isShapeOutside() || blockAdjust()==false){
                currentShape.move(0,1);
            }
        }
        }
    
        else if(key==KEY_UP){
            if(!gameover){
            currentShape.rotateShape();
            if(isShapeOutside() || blockAdjust()==false){
                currentShape.reverseRotation();
            }
            else{
                PlaySound(roatate);
            }
        }
    }
        else if(key==KEY_DOWN){
            if(!gameover){
            currentShape.move(2,0);
            if(isShapeOutside() || blockAdjust()==false){
                currentShape.move(-2,0);
                updateScore(0,1);
                score+=1;
                LockShape();
            }

        }
        }  
        else if(key==KEY_SPACE){
            if(!gameover){
                currentShape.move(6,0);
                if(isShapeOutside() || blockAdjust()==false){
                    currentShape.move(-6,0);
                    updateScore(0,1);
                    score+=1;
                    LockShape();
                }
    
            }
        }
    }
}


bool Game::isShapeOutside()
{
    if(level==1){
        vector<Shapeposition> position=currentShape.GetCellPositions();
        for (Shapeposition item:position )
        {
            if(grid.isShapeOutside(item.row,item.column)){
                return true;
            }
        }
        return false;
    }
    else if(level==2){
        vector<Shapeposition> position=currentShape.GetCellPositions();
        for (Shapeposition item:position )
        {
            if(grid.isShapeOutside(item.row,item.column)){
                return true;
            }
        }
        return false;
    }
    return false;
}
void Game::rotateShape()
{
    if(level==1){
    currentShape.rotateShape();
    }
    else if(level==2){
        currentShape.rotateShape();
        }
}
void Game::fallBlock()
{
    if(level==1){
    if (!blockAdjust()) {
        gameover = true;
        return;
    }
    currentShape.move(1,0);
    if(isShapeOutside() || blockAdjust()==false){
    currentShape.move(-1,0);
    LockShape();
    }
    }
   else if(level==2){
        if (!blockAdjust()) {
            gameover = true;
            return;
        }
        currentShape.move(2,0);
        if(isShapeOutside() || blockAdjust()==false){
        currentShape.move(-2,0);
        LockShape();
        }
        }

}

void Game::LockShape()
{
    if(level==1){
    vector<Shapeposition> shapeposition=currentShape.GetCellPositions();
    for (Shapeposition item:shapeposition)
    {
        grid.grid[item.row][item.column]=currentShape.id;
    }

      currentShape=nextShape;
      if(blockAdjust()==false){
        gameover=true;
      }

      nextShape=*(getRandomShape());
      int rowsclear=grid.ClearFullRows();
      if(rowsclear>0){
        PlaySound(clearsound);
      }
      updateScore(rowsclear,0);
    }
    else if(level==2){
        vector<Shapeposition> shapeposition=currentShape.GetCellPositions();
        for (Shapeposition item:shapeposition)
        {
            grid.grid[item.row][item.column]=currentShape.id;
        }
          currentShape=nextShape;
          if(blockAdjust()==false){
            gameover=true;
          }
          nextShape=*(getRandomShape());
          int rowsclear=grid.ClearFullRows();
          if(rowsclear>0){
            PlaySound(clearsound);
          }
          updateScore(rowsclear,0);
        }
}
bool Game::blockAdjust()
{
    if(level==1){
        vector<Shapeposition> shapeposition=currentShape.GetCellPositions();
        for(Shapeposition item:shapeposition){
            if(grid.isCellvacant(item.row,item.column)==false){
                return false;
            }
        }
        return true;
    }
    else if(level==2){
        vector<Shapeposition> shapeposition=currentShape.GetCellPositions();
        for(Shapeposition item:shapeposition){
            if(grid.isCellvacant(item.row,item.column)==false){
                return false;
            }
        }
        return true;
    }
    return true; 
}
Shape **Game::getAllBlocks()
{
    if(level==1){
        return shape;
    }
    else if(level==2){
        return shape;
    }
    return shape;
}
void Game::reset() {
    if(level==1){
    grid.initialize();
    for (int i = 0; i < 7; ++i) {
        shapeUsed[i] = false;
    }
    shapecount= 0;
    currentShape = *getRandomShape();
    nextShape = *getRandomShape();
    gameover = false;
    score=0;
}
    else if(level==2){
        grid.initialize();
        for (int i = 0; i < 8; ++i) {
            shapeUsed[i] = false;
        }
        shapecount= 0;
        currentShape = *getRandomShape();
        nextShape = *getRandomShape();
        gameover = false;
        score=0;
    }    
}
