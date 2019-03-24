#include "player.h"
void Player::highscore(Player &a)
{
    int sc=0;
    string playerName;
    ifstream file_i;
    ofstream file_o;
    file_i.open("data/score.txt");
    file_i>>playerName>>sc;
    if(score>=a.score){
        if (score>=sc)
        {
            sc=score;
            file_i.close();
            file_o.open("data/score.txt");
            file_o<<name<<endl;
            file_o<<sc;
            file_o.close();
        }
    }
    else{
        if (a.score>=sc)
        {
            sc=a.score;
            file_i.close();
            file_o.open("data/score.txt");
            file_o<<a.name<<endl;
            file_o<<sc;
            file_o.close();
        }
    }
}

void Player::HangManScore(Player &a)
{
    int sc=0;
    string playerName;
    ifstream file_i;
    ofstream file_o;
    file_i.open("data/Hscore.txt");
    file_i>>playerName>>sc;
    if(score>=a.score){
        if (score>=sc)
        {
            sc=score;
            file_i.close();
            file_o.open("data/Hscore.txt");
            file_o<<name<<endl;
            file_o<<sc;
            file_o.close();
        }
    }
    else{
        if (a.score>=sc)
        {
            sc=a.score;
            file_i.close();
            file_o.open("data/Hscore.txt");
            file_o<<a.name<<endl;
            file_o<<sc;
            file_o.close();
        }
    }
}
