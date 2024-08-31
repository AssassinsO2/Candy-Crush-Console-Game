#include"Candy.h"

Candy::Candy()
{
	type = '\0';
	color = 0;
}

Candy::Candy(char t, int c)
{
	type = t;
	color = c;
}

void Candy::SetAttributes(Candy& Obj)
{
	type = Obj.type;
	color = Obj.color;
}

void Candy::display()
{
	setColor(color);
	cout << type;
	setColor(7);
	cout << " ";
}