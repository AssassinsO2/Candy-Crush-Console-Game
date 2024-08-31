#include"Player.h"

player::player()
{
    player_id = 0;
    username = nullptr;
    at_level = 0;
    high_score = 0;
    player_rank = 0;
    current_money = 0;
    current_xp = 0;
}

player::player(int p_id, const char* name, int& level, int& h_score, int& pRank, int& cmoney, int& xp)
{
    username = new char[20];
    int i = 0;
    for (; name[i] != '\0'; i++)
    {
        username[i] = name[i];
    }
    username[i] = '\0';

    player_id = p_id;
    at_level = level;
    high_score = h_score;
    player_rank = pRank;
    current_money = cmoney;
    current_xp = xp;
}

player::player(const player& Obj)
{
    player_id = Obj.player_id;

    username = new char[20];
    int i = 0;
    for (; Obj.username[i] != '\0'; i++)
    {
        username[i] = Obj.username[i];
    }
    username[i] = '\0';

    at_level = Obj.at_level;
    high_score = Obj.high_score;
    player_rank = Obj.player_rank;
    current_money = Obj.current_money;
    current_xp = Obj.current_xp;
}

void player::updatePlayer_level()
{
    int level_target = (player_rank + 1) * ((player_rank + 1) * 1000);

    if (current_xp >= level_target)
    {
        player_rank++;
        cout << "Player Rank Increase new rank is: " << player_rank << endl;
    }
}

void player::updateCurrent_xp(int& xp)
{
    current_xp = current_xp + xp;
}

void player::updateAt_level(int& level)
{
    at_level = level;
}

void player::updateHigh_score(int& score)
{
    if (score > high_score)
    {
        high_score = score;
    }
}

void player::updateCurrent_money(int& money)
{
    current_money = current_money + money;
}

void player::UpdateAttributes(int& level, int& h_score, int& pRank, int& cmoney, int& xp)
{
    at_level = level;
    high_score = h_score;
    player_rank = pRank;
    current_money = cmoney;
    current_xp = xp;
}

char* player::getUserName()
{
    return username;
}

int player::getCurrent_xp()
{
    return current_xp;
}

int player::getCurrent_rank()
{
    return player_rank;
}

int player::getPlayerRank()
{
    return player_rank;
}

int player::getAt_level()
{
    return at_level;
}