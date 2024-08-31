#ifndef DLINKEDLIST_H
#define DLINKEDLIST_H
#include"Candy.h"

class dnode
{
public:
	Candy candy;
	dnode* next;
	dnode* previous;
	dnode(Candy c);
};

class Dlist
{
	dnode* first;
public:
	Dlist();
	bool isEmpty();
	void insert(Candy c);
	void ForwardDisplay();
	bool colMatch(Candy candy, int limit);
	bool rowMatch(Candy candy, int limit, char key);
	int FindSize();
	Dlist FindMatches(int& StartIndex, int& EndIndex, int& CandiesToCrush);
	int calPoints(int& points);
	void removeDup();
};
#endif
