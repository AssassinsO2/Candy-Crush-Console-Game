#ifndef LEVEL_H
#define LEVEL_H
#include<iostream>
using namespace std;

class Level
{
    int levelNumber;
    int targetScore;
    int candiesToClear;
    int moves;
    int rows;
    int cols;
    string difficulty;

public:
    Level();
    Level(int ln, int ts, int CC, int m, int r, int c, string d);
    void UpdateAttributes(int ln, int ts, int CC, int m, int r, int c, string d);
    int getLevelNumber();
    int getTargetScore();
    int getCandiesToClear();
    int getMoves();
    int getRows();
    int getCols();
    string getDifficulty();
    bool operator==(Level& other);
    void display();

    friend ostream& operator<<(ostream& os, const Level& l)
    {
        os << "levelNumber: " << l.levelNumber << endl;
        os << "targetScore: " << l.targetScore << endl;
        os << "candiesToClear: " << l.candiesToClear << endl;
        os << "moves: " << l.moves << endl;
        os << "difficulty: " << l.difficulty << endl;
        return os;
    }
};
#endif
