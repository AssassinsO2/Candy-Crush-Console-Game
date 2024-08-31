#ifndef PLAYER_H
#define PLAYER_H
#include<iostream>
using namespace std;

class player
{
    int player_id;
    char* username;
    int at_level;
    int high_score;
    int player_rank;
    int current_money;
    int current_xp;

public:
    player();
    player(int p_id, const  char* name, int& level, int& h_score, int& pRank, int& cmoney, int& xp);
    player(const player& Obj);
    void updatePlayer_level();
    void updateAt_level(int& level);
    void updateHigh_score(int& score);
    void updateCurrent_money(int& money);
    void updateCurrent_xp(int& xp);
    void UpdateAttributes(int& level, int& h_score, int& pRank, int& cmoney, int& xp);
    char* getUserName();
    int getCurrent_xp();
    int getCurrent_rank();
    int getPlayerRank();
    int getAt_level();
    friend ostream& operator<<(ostream& os, const player& p)
    {
        os << "Username: " << p.username << endl;
        os << "Player Rank: " << p.player_rank << endl;
        os << "Currently at level: " << p.at_level << endl;
        os << "Highest Score: " << p.high_score << endl;
        os << "Player money: " << p.current_money << endl;
        return os;
    }
};

#endif
