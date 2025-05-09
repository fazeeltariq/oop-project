#ifndef PLAYER
#define PLAYER
#include<iostream>
#include<fstream>
#include<vector>
using namespace std;

class Player{
    private:
    string playername;
    string playerpassword;
    int playerscore;
    public:
    Player();
    Player(string name,string password);
    void addDetails();
    void updatescore(int score);
    int maxscore();
};

#endif
