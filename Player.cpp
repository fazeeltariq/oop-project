#include "Player.h"

Player::Player() {}

Player::Player(string name,string password) {
    playername=name;
    playerpassword=password;
    playerscore=0;
}
int Player::maxscore() {
    ifstream f("player.txt");
    try {
        if (!f.is_open()) {
            throw "Cannot open file for reading: ";
        }
        int maximumscore=0;
        string line;
        while (getline(f,line)) {
            if (line.find("Name: " + playername)!=string::npos) {
                string passLine,scoreLine;
                getline(f,passLine); 
                getline(f,scoreLine);
                if (passLine.find("Password: " + playerpassword) != string::npos) {
                    int score = 0;
                    sscanf(scoreLine.c_str(), "Max score: %d", &score);
                    if (score>maximumscore) {
                        maximumscore=score;
                    }
                }
            }
        }
        f.close();
        return maximumscore;
    }
    catch(const char* error) {
        cout<<error<<"\n";
    }
    return 0;
}
void Player::addDetails()
{
    ifstream playerfile("player.txt");
    string line;
    bool isupdated=false;
    vector<string> filedata;
    while (getline(playerfile, line)) {
        if (line.find("Name: " + playername) != string::npos) {
            string passwordline, scoreline;
            getline(playerfile, passwordline);
            getline(playerfile, scoreline);

            if (passwordline.find("Password: " + playerpassword) != string::npos) {
                int lastscore=0;
                sscanf(scoreline.c_str(), "Max score: %d", &lastscore);

                if (playerscore>lastscore) {
                    scoreline="Max score: " + to_string(playerscore);
                }
                isupdated=true;
                filedata.push_back(line);       
                filedata.push_back(passwordline);     
                filedata.push_back(scoreline);
                continue;
            } else {
                filedata.push_back(line);
                filedata.push_back(passwordline);
                filedata.push_back(scoreline);
                continue;
            }
        }
        filedata.push_back(line);
    }
    playerfile.close();
    if (!isupdated) {
        filedata.push_back("---------------------------");
        filedata.push_back("Name: " +playername);
        filedata.push_back("Password: " +playerpassword);
        filedata.push_back("Max score: " +to_string(playerscore));
    }
    ofstream writedata("player.txt");
    for (const string& f : filedata) {
        writedata<<f<<"\n";
    }
    writedata.close();
}

void Player::updatescore(int score) {
    playerscore = score;
}

