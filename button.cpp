#include"button.h"
#include<iostream>


Button::Button(float buttonX, float buttonY,float buttonW,float buttonH,Color buttonColor, Color textColor)
{
    buttonpositionX=buttonX;
    buttonpositionY=buttonY;
    buttonWidth=buttonW;
    buttonHeight=buttonH;
    playbutton={ buttonpositionX, buttonpositionY, buttonWidth, buttonHeight };
    this->buttonColor=buttonColor;
    buttonTextColor=textColor;
    isHover = false;
}

void Button::DrawButton(){
    DrawRectangleRec(playbutton, isHover ? LIGHTGRAY : buttonColor);   // draws a filled rectangle
}

void Button::makeButtonHover(Vector2 mouseposition){
    isHover=CheckCollisionPointRec(mouseposition,playbutton);
}

void Button::DrawTextinButton(const char* buttontext,int textWidth){
    DrawText(buttontext, buttonpositionX + (buttonWidth - textWidth) / 2, buttonpositionY + 15, 20, buttonTextColor);
}

Rectangle Button::getplayButton(){
    return playbutton;
}




