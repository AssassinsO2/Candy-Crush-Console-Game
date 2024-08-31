#ifndef HEADER_H
#define HEADER_H
#include<iostream>
#include<Windows.h>
#include<conio.h>
#include<algorithm>
#include<random> 
#include<iomanip>
#include"Level.h"
#include"SLinked list.cpp"
using namespace std;

void setColor(int color);
void gotoxy(short x, short y);
void PrintWelcome();
void PrintUserName(char* username, int& plevel, int& h_score, short y);
char levelSelector(int& levelSelectorCounter, int& level_counter, char* username);
void instruction();
void scoreDisplay(int& score);
void movesDisplay(int& moves);
void RemainingCandies(int& CandiesToClear);
void levelDisplay(int& level, int& target, string difficulty, int& candiesToCrush);
char candySelection(int& rows, int& cols, int& r, int& c);
char generateNewCommand(int& NC);
void UpdateRC(char key, int& r, int& c);
void insertLevels(Slist<Level>& S);
bool generateNewBoard();
#endif