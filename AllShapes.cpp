#include "Shape.h"
#include "raylib.h"
#include "Shapeposition.h"


class UShape : public Shape {
    public:
        UShape() {
            rotationState = 0;
            id = 8;

            position[1][0]= Shapeposition(0, 0);
            position[1][1] =Shapeposition(1, 0);
            position[1][2] =Shapeposition(2, 0);
            position[1][3]=Shapeposition(2, 1);

            position[0][0]  =Shapeposition(0, 0);
            position[0][1]= Shapeposition(1, 0);
            position[0][2]= Shapeposition(0, 1);
            position[0][3]=Shapeposition(0, 2);
    
            position[2][0]= Shapeposition(1, 2);
            position[2][1] =Shapeposition(1, 1);
            position[2][2] =Shapeposition(0, 2);
            position[2][3]=Shapeposition(1, 0);
    
            position[3][0]= Shapeposition(0, 1);
            position[3][1]= Shapeposition(0, 2);
            position[3][2]= Shapeposition(1, 2);
            position[3][3] =Shapeposition(2, 2);
            move(0, 4);
        }
    };
    
class IShape:public Shape{
    public:
    IShape(){
    rotationState = 0;
    id = 1;
    position[0][0]= Shapeposition(1,0); position[0][1]=Shapeposition(1,1); 
    position[0][2] =Shapeposition(1,2); position[0][3]= Shapeposition(1,3);

    position[1][0]= Shapeposition(0,2); position[1][1]=Shapeposition(1,2); 
    position[1][2] =Shapeposition(2,2); position[1][3]=Shapeposition(3, 2);

    position[2][0]=Shapeposition(2,0); position[2][1]=Shapeposition(2,1); 
    position[2][2] =Shapeposition(2,2); position[2][3]=Shapeposition(2, 3);

    position[3][0]= Shapeposition(0,1);  position[3][1]=Shapeposition(1,1);
    position[3][2]=Shapeposition(2,1); position[3][3]=  Shapeposition(3, 1);

    move(-1,3);
    }
};
class ZShape:public Shape{
    public:
    ZShape(){
    rotationState = 0;
    id = 5;
    position[0][0]=Shapeposition(0,0); position[0][1]=Shapeposition(0,1); 
    position[0][2]= Shapeposition(1,1); position[0][3]=Shapeposition(1,2);

    position[1][0]= Shapeposition(0,2); position[1][1]= Shapeposition(1,1); 
    position[1][2]=Shapeposition(1,2); position[1][3]= Shapeposition(2, 1);

    position[2][0]=Shapeposition(1,0); position[2][1] =Shapeposition(1,1); 
    position[2][2]= Shapeposition(2,1); position[2][3]=Shapeposition(2, 2);

    position[3][0]=Shapeposition(0,1); position[3][1] =Shapeposition(1,0);
    position[3][2]= Shapeposition(1,1); position[3][3] =Shapeposition(2, 0);

    move(0,3);
    }
};
class JShape:public Shape{
    public:
    JShape(){
        id=6;
        position[0][0]= Shapeposition(0,0); position[0][1]= Shapeposition(1,0); 
        position[0][2]=Shapeposition(1,1); position[0][3] =Shapeposition(1,2);
    
        position[1][0]= Shapeposition(0,1); position[1][1]=Shapeposition(0,2); 
        position[1][2]= Shapeposition(1,1); position[1][3]=Shapeposition(2, 1);
    
        position[2][0] =Shapeposition(1,0); position[2][1]=Shapeposition(1,1); 
        position[2][2] =Shapeposition(1,2); position[2][3]=Shapeposition(2, 2);
    
        position[3][0] =Shapeposition(0,1); position[3][1]= Shapeposition(1,1);
        position[3][2]=Shapeposition(2,0); position[3][3] =Shapeposition(2, 1);
        move(0,3);
    }
};
class TShape:public Shape{
    public:
    TShape(){
        id=3;
        position[0][0] =Shapeposition(0,1); position[0][1]= Shapeposition(1,0); 
        position[0][2]= Shapeposition(1,1); position[0][3]= Shapeposition(1,2);
    
        position[1][0] =Shapeposition(0,1); position[1][1]= Shapeposition(1,1); 
        position[1][2]= Shapeposition(1,2); position[1][3] =Shapeposition(2, 1);
    
        position[2][0]=Shapeposition(1,0); position[2][1]= Shapeposition(1,1); 
        position[2][2] =Shapeposition(1,2); position[2][3]= Shapeposition(2, 1);
    
        position[3][0]= Shapeposition(0,1); position[3][1]= Shapeposition(1,0);
        position[3][2]= Shapeposition(1,1); position[3][3]= Shapeposition(2, 1);
        move(0,3);
    }  
};

class LShape: public Shape{
    public:
    LShape(){
        id=7;
        position[0][0]= Shapeposition(0,2); position[0][1] =Shapeposition(1,0); 
        position[0][2] =Shapeposition(1,1); position[0][3]= Shapeposition(1,2);
    
        position[1][0]= Shapeposition(0,1); position[1][1] = Shapeposition(1,1); 
        position[1][2] =Shapeposition(2,1); position[1][3]= Shapeposition(2, 2);
    
        position[2][0] =Shapeposition(1,0); position[2][1]= Shapeposition(1,1); 
        position[2][2] =Shapeposition(1,2); position[2][3]= Shapeposition(2, 0);
    
        position[3][0] =Shapeposition(0,0); position[3][1]= Shapeposition(0,1);
        position[3][2]= Shapeposition(1,1); position[3][3]= Shapeposition(2, 1);
        move(0,3);
    }  
};
class OShape:public Shape{
    public:
    OShape(){   
        id=2;
        position[0][0] = Shapeposition(0,0); position[0][1]= Shapeposition(0,1); 
        position[0][2] = Shapeposition(1,0); position[0][3]= Shapeposition(1,1);

        position[0][0] = Shapeposition(0,0); position[0][1]= Shapeposition(0,1); 
        position[0][2] = Shapeposition(1,0); position[0][3]= Shapeposition(1,1);

        position[0][0] =Shapeposition(0,0); position[0][1]= Shapeposition(0,1); 
        position[0][2]= Shapeposition(1,0); position[0][3] = Shapeposition(1,1);

        position[0][0]= Shapeposition(0,0); position[0][1]= Shapeposition(0,1); 
        position[0][2]= Shapeposition(1,0); position[0][3]= Shapeposition(1,1);
        move(0,4);
    }  
};

class SShape:public Shape{
    public:
    SShape(){
    id=4;
    position[0][0]= Shapeposition(0,1); position[0][1]= Shapeposition(0,2); 
    position[0][2]= Shapeposition(1,0); position[0][3] =Shapeposition(1,1);

    position[0][0]= Shapeposition(0,1); position[0][1]= Shapeposition(1,1); 
    position[0][2]= Shapeposition(1,2); position[0][3]= Shapeposition(2,2);

    position[0][0]= Shapeposition(1,1); position[0][1]= Shapeposition(1,2); 
    position[0][2]= Shapeposition(2,0); position[0][3]=Shapeposition(2,1);

    position[0][0] =Shapeposition(0,0); position[0][1]=Shapeposition(1,0); 
    position[0][2] = Shapeposition(1,1); position[0][3]=Shapeposition(2,1);
    move(0,3);
    }

};
