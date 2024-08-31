#include"Level.h"

Level::Level()
{
    levelNumber = 0;
    targetScore = 0;
    candiesToClear = 0;
    moves = 0;
    rows = 0;
    cols = 0;
    difficulty = " ";
}

Level::Level(int ln, int ts, int CC, int m, int r, int c, string d)
{
    levelNumber = ln;
    targetScore = ts;
    candiesToClear = CC;
    moves = m;
    rows = r;
    cols = c;
    difficulty = d;
}

void Level::UpdateAttributes(int ln, int ts, int CC, int m, int r, int c, string d)
{
    levelNumber = ln;
    targetScore = ts;
    candiesToClear = CC;
    moves = m;
    rows = r;
    cols = c;
    difficulty = d;
}

int Level::getLevelNumber()
{
    return levelNumber;
}

int Level::getTargetScore()
{
    return targetScore;
}

int Level::getCandiesToClear()
{
    return candiesToClear;
}

int Level::getMoves()
{
    return moves;
}

int Level::getRows()
{
    return rows;
}

int Level::getCols()
{
    return cols;
}

string Level::getDifficulty()
{
    return difficulty;
}

bool Level::operator==(Level& Obj)
{
    if (levelNumber == Obj.levelNumber)
    {
        Obj.levelNumber = levelNumber;
        Obj.candiesToClear = candiesToClear;
        Obj.targetScore = targetScore;
        Obj.moves = moves;
        Obj.difficulty = difficulty;
        Obj.rows = rows;
        Obj.cols = cols;
        return true;
    }
    return false;
}

void Level::display()
{
    cout << "levelNumber: " << levelNumber << endl;
    cout << "targetScore: " << targetScore << endl;
    cout << "candiesToClear: " << candiesToClear << endl;
    cout << "moves " << moves << endl;
    cout << "difficulty: " << difficulty << endl;
}