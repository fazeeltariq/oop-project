#include"Shape.h"
#include"Grid.h"
#include"Player.h"

class Game{
    private:
    Grid grid;
    Shape* shape[8];
    bool shapeUsed[8];
    int shapecount;
    Shape currentShape;
    Shape nextShape;
    int level=1;
    public:
    int score;
    Music music;
    Sound roatate;
    Sound clearsound;
    Shape** getAllBlocks();
    void DrawGame();
    void MoveShapes();
    bool isShapeOutside();
    void rotateShape();
    void fallBlock();
    void LockShape();
    bool blockAdjust();
    bool gameover;
    void reset();
    void updateScore(int lines,int movedownpoints);
    Shape *getRandomShape();
    Game(int level);
    ~Game();
};