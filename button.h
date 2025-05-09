#ifndef BUTTON
#define BUTTON
#include<iostream>
#include<raylib.h>
using namespace std;

class Button{
    private:
    Color buttonColor;
    Color buttonTextColor;
    float buttonpositionX;
    float buttonpositionY;
    float buttonHeight;
    float buttonWidth;
    bool isHover;
    Rectangle playbutton;
    Vector2 mouseposition;

    public:
    Button(float buttonX, float buttonY,float buttonW,float buttonH,Color buttonColor, Color textColor);
    
    void DrawButton();
    void DrawTextinButton(const char* hello,int textWidth);
    void makeButtonHover(Vector2 mouseposition);
    bool isButtonClick();
    bool IsHovered(Vector2 mouse);
    Rectangle getplayButton();
    
};
#endif