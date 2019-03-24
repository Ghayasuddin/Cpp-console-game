#ifndef  PLAYER_H_INCLUDED
#define  PLAYER_H_INCLUDED

class Player{
protected:
    string name;
    int score;
public:
    Player(){
        name = "UNKNOWN";
        score = 0;
    }
    void highscore(Player &);
    void HangManScore(Player &);
    string getName(){
        return name;
    }

    int getScore(){
        return score;
    }
    void setName(string name){
        this->name = name;
    }
    void setScore(int score){
        this->score = score;
    }

    ~Player(){}

};

#endif
