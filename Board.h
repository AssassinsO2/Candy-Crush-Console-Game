#ifndef BOARD_H
#define BOARD_H
#include"DLinked List.h"
#include"Queue.cpp"

void shuffleCandies(Candy candies[], int size);

class Board
{
	int rows, cols;
	Candy** board;
public:
	Board(int r, int c);
	~Board();

	void removeDup();
	void display(int r, int c, int b);
	bool autoCrush(int& points, int& CandiesToCrush);
	void swapCandy(char& key, int& r, int& c);
	bool swapPossible(int& r, int& c, char& key);
	void EvaluateMatch(char& key, int r, int c, int& points, int& CandiesToCrush);
	void replaceCandiesForRow(int& r, int& c, char& next, int SI, int EI);
	void replaceCandiesForCol(int& r, int& c, char& next, int SI, int EI);
	void SpecialMoves(char& next, int& r, int& c, Candy& oldCandy, int SI, int EI, int& middle, char secondKey);
	void GenerateNewCandies(int& r, int& c, int SI, int EI, char& secondKey);
};
#endif
