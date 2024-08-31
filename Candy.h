#ifndef CANDY_H
#define CANDY_H
#include"header.h"

class Candy
{
public:
	char type;
	int color;
	Candy();
	Candy(char t, int c);
	void SetAttributes(Candy& Obj);
	void display();
};
#endif
