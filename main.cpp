#include <iostream>
#include <raylib.h>
#include "button.h"
#include "Grid.h"
#include "Shape.h"
#include "AllShapes.cpp"
#include "Game.h"
#include "Player.h"
using namespace std;

const int SCREEN_WIDTH=755;
const int SCREEN_HEIGHT=670;
Color midnightBlue={25,25,112,255};
Color deepSpace ={11,12,40,255};
Color gridBackground={30,30,30,255};
Color darkGray ={45,45,45,255};
Color inputTextColor={30,30,30,255};
Color loginButtonColor={100,149,237,255};

int main() {

    InitWindow(SCREEN_WIDTH,SCREEN_HEIGHT,"TETRIS");
    SetTargetFPS(60);
    int level=0;
    bool playbuttonclicked=false;
    char name[40]="\0";
    char password[40]="\0";
    Rectangle usernamebox={310,195,200,25};
    Rectangle userpasswordBox={310,245,200,25};

    Texture2D backgroundimage=LoadTexture("image.png");
    Button playButton(SCREEN_WIDTH/2-75,SCREEN_HEIGHT/2-100,150,50,WHITE,BLACK);
    const char* buttontext="Play Game";

    Button easylevelbutton(SCREEN_WIDTH/2-75,SCREEN_HEIGHT/2-30,150,50,WHITE,BLACK);
    const char* easylevel="Easy Level";

    int nameLength=0;
    int passwordLength=0;
    bool istypingname=false;
    bool istypingPassword=false;

    bool logindone=false;
    bool gamebegin=false;

    Button hardlevelbutton(SCREEN_WIDTH/2-75,SCREEN_HEIGHT/2+30,150,50,WHITE,BLACK);
    const char* hardlevel="Hard Level";

    int textWidth=MeasureText(buttontext,20);
    int textWidtheasy=MeasureText(easylevel,20);
    int textWidthhard=MeasureText(hardlevel,20);

    Game* game=nullptr;
    Player player;
    double lastFallTime=0.0;
    const float fallInterval=0.5f;
    Font font=LoadFontEx("Orbiton-Bold",64,0,0);
    bool isloginhover=false;
    bool isnamehover=false;
    bool ispasswordhover=false;

    while (!WindowShouldClose()) {
        Vector2 mouse=GetMousePosition();
        if (!logindone){
            if (CheckCollisionPointRec(mouse,usernamebox)) 
            {
                isnamehover=true;
                if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
                    istypingname=true;
                    istypingPassword=false;
                }
            } else
             {
                isnamehover=false;
            }
            if (CheckCollisionPointRec(mouse, userpasswordBox))
             {
                ispasswordhover=true;
                if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
                    istypingname=false;
                    istypingPassword=true;
                }
            } else
             {
                ispasswordhover=false;
            }
            int input=GetCharPressed();
            while (input>0)
             {
                if(istypingPassword && passwordLength<39) {
                    password[passwordLength]=(char)input;
                    passwordLength++;
                    password[passwordLength]='\0';
                }
                 else if(istypingname && nameLength<39) {
                    name[nameLength]=(char)input;
                    nameLength++;
                    name[nameLength]='\0';
                }
                input=GetCharPressed();
            }
            if (IsKeyPressed(KEY_BACKSPACE))
             {
                if (istypingname && nameLength>0) {
                    name[--nameLength]='\0';
                } else if(istypingPassword && passwordLength > 0) {
                    password[--passwordLength]='\0';
                }
            }
            if (IsKeyPressed(KEY_TAB))
             {
                istypingname=!istypingname;
                istypingPassword=!istypingPassword;
            }
            if (CheckCollisionPointRec(mouse,{275,375,250,40}))
             {
                isloginhover=true;
                if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) 
                {
                    logindone=true;
                    player=Player(name,password);
                }
            } else 
            {
                isloginhover=false;
            }
        }
      if (logindone && !gamebegin) {
    Vector2 mouse=GetMousePosition();

    if (!playbuttonclicked && CheckCollisionPointRec(mouse, playButton.getplayButton()) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
    {
        playbuttonclicked=true;
    }

    if (playbuttonclicked){
        if (level==0){
            if(CheckCollisionPointRec(mouse,easylevelbutton.getplayButton()) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
                level=1;
            }
            else if(CheckCollisionPointRec(mouse,hardlevelbutton.getplayButton()) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
                level=2; 
            }
        }

        if (level!=0) {
             game=new Game(level);
            gamebegin=true;
            lastFallTime=GetTime();
        }
    }
    }
        BeginDrawing();
        ClearBackground(RAYWHITE);

        if (!logindone){
            ClearBackground(darkGray);
            DrawRectangle(200,150,400,300,RAYWHITE);
            DrawText("Name:",220,200,18,DARKGRAY);
            DrawRectangleRec(usernamebox,isnamehover ? GRAY : LIGHTGRAY);
            DrawText(name,318,200,18,inputTextColor);

            DrawText("Password:",220,250,18,DARKGRAY);
            DrawRectangleRec(userpasswordBox,ispasswordhover ? GRAY : LIGHTGRAY);
            DrawText(password,318,250,18,inputTextColor);

            DrawRectangle(275,375,250,40,isloginhover ? loginButtonColor:(Color){0,0,139,255});
            DrawText("SIGN IN",367,385,20,WHITE);
        }

        else if (!gamebegin){
            playButton.makeButtonHover(mouse);
            DrawTexture(backgroundimage,-69,-20,WHITE);
            playButton.DrawButton();
            playButton.DrawTextinButton(buttontext,textWidth);
            easylevelbutton.makeButtonHover(mouse);
            easylevelbutton.DrawButton();
            easylevelbutton.DrawTextinButton(easylevel,textWidtheasy);
            hardlevelbutton.makeButtonHover(mouse);
            hardlevelbutton.DrawButton();
            hardlevelbutton.DrawTextinButton(hardlevel,textWidthhard);
        }
        else {
            ClearBackground(deepSpace);
            UpdateMusicStream(game->music);
            DrawTextEx(font,"Score",{437,30},34,2,WHITE);
            DrawTextEx(font,"Next Shape",{410, 330},34,2,WHITE);
            if (game->gameover) {
                DrawTextEx(font, "Game Over!",{410, 550},34,2,WHITE);
                player.addDetails();
                player.updatescore(game->score);
            }

            char score[10];
            sprintf(score,"%d",game->score);
            Vector2 textsize=MeasureTextEx(font,score,38,2);
            DrawRectangleRounded({435,70,180,60},0.3,6,midnightBlue);
            DrawTextEx(font,score,{425+(95-textsize.x),80},34,2,WHITE);
            DrawRectangleRounded({405,380,230,120},0.3,6,midnightBlue);
            game->DrawGame();
            game->MoveShapes();
            double currentTime=GetTime();
            if (currentTime-lastFallTime>=fallInterval) {
                game->fallBlock();
                lastFallTime=currentTime;
            }
        }
        EndDrawing();
    }
    UnloadTexture(backgroundimage);
    CloseWindow();
    return 0;
}