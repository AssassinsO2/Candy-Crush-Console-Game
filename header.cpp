#include"header.h"

HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);

void setColor(int color)
{
	SetConsoleTextAttribute(h, color);
}

void gotoxy(short x, short y)
{
	COORD pos = { x, y };
	SetConsoleCursorPosition(h, pos);
}

void PrintWelcome()
{
	setColor(9);
	gotoxy(5, 1);
	cout << "-----------------WELCOME TO CANDY CRUSH SAGA--------------------" << endl;

	setColor(14);
	gotoxy(20, 24);
	cout << "MADE BY: MUHAMMAD HUZAIFA";
	gotoxy(25, 25);
	cout << "L1S22BSCS0064" << endl;
}

void PrintUserName(char* username, int& plevel, int& h_score, short y)
{
	setColor(12);
	gotoxy(5, y);
	cout << "USER: " << username;
	gotoxy(28, y);
	cout << "RANK: " << plevel;
	gotoxy(40, y);
	cout << "HIGHEST SCORE: " << h_score << endl;
}

void instruction()
{
	setColor(14);
	gotoxy(5, 2);
	cout << "Use 'w', 'a', 's', 'd' to move cursor up, down, left and right";

	gotoxy(5, 3);
	cout << "Press 'i', 'j', 'k', 'l' to move candy up, down, left and right";

	setColor(4);
	gotoxy(5, 22);
	cout << "Press 'e' to exit.";
}

char levelSelector(int& levelSelectorCounter, int& level_counter, char* username)
{
	for (;;)
	{
		setColor(10);
		gotoxy(5, 16);
		cout << "Select level number " << endl;
		setColor(4);
		gotoxy(5, 18);
		cout << "PRESS E TO EXIT." << endl;
		int i = 1;
		for (; i <= 10; i++)
		{
			if (i == levelSelectorCounter)
			{
				setColor(7);
			}
			else
			{
				setColor(10);
			}
			gotoxy(5, 4 + i);
			cout << "Level " << i << endl;
		}

		char key = _getch();

		if ((key == 'w' || key == 'W') && levelSelectorCounter > 1)
		{
			levelSelectorCounter--;
		}
		else if ((key == 's' || key == 'S') && levelSelectorCounter < 10)
		{
			levelSelectorCounter++;
		}
		else if (key == 13)
		{
			if (levelSelectorCounter <= level_counter)
			{
				system("ClS");

				setColor(10);
				gotoxy(5, 6);

				cout << "Level " << levelSelectorCounter << " selected." << endl;
				return '\0';
			}
			else
			{
				setColor(4);
				gotoxy(5, 4 + levelSelectorCounter);

				cout << "Level " << levelSelectorCounter << " currently locked play previous level to unlock" << endl;
			}
		}
		else if (key == 'E' || key == 'e')
		{
			return key;
		}
	}
}

void scoreDisplay(int& score)
{
	int i = 10;
	setColor(4);
	gotoxy(28, i);
	cout << "----------";

	setColor(4);
	gotoxy(28, i + 1);
	cout << "|";
	gotoxy(28, i + 2);
	cout << "|";

	setColor(10);
	gotoxy(30, i + 1);
	cout << "SCORES";

	setColor(4);
	gotoxy(37, i + 1);
	cout << "|";

	setColor(10);
	gotoxy(30, i + 2);
	cout << score;

	setColor(4);
	gotoxy(37, i + 2);
	cout << "|";

	setColor(4);
	gotoxy(28, i + 3);
	cout << "----------";
}

void movesDisplay(int& moves)
{
	int i = 14;
	setColor(4);
	gotoxy(28, i);
	cout << "|";
	gotoxy(28, i + 1);
	cout << "|";

	setColor(10);
	gotoxy(30, i);
	cout << "MOVES";

	setColor(4);
	gotoxy(37, i);
	cout << "|";

	setColor(10);
	gotoxy(30, i + 1);
	cout << moves;

	setColor(4);
	gotoxy(37, i + 1);
	cout << "|";

	setColor(4);
	gotoxy(28, i + 2);
	cout << "----------";
}

void RemainingCandies(int& CandiesToClear)
{
	int i = 17;
	setColor(4);
	gotoxy(28, i);
	cout << "|";
	gotoxy(28, i + 1);
	cout << "|";
	gotoxy(28, i + 2);
	cout << "|";

	setColor(10);
	gotoxy(30, i);
	cout << "Candies";
	gotoxy(30, i + 1);
	cout << "Left";

	setColor(4);
	gotoxy(37, i);
	cout << "|";
	gotoxy(37, i + 1);
	cout << "|";


	setColor(10);
	gotoxy(30, i + 2);
	cout << CandiesToClear;

	setColor(4);
	gotoxy(37, i + 2);
	cout << "|";
	setColor(4);

	setColor(4);
	gotoxy(28, i + 3);
	cout << "----------";
}

void levelDisplay(int& level, int& target, string difficulty, int& candiesToCrush)
{
	setColor(3);
	gotoxy(5, 7);
	cout << "Level " << level;

	gotoxy(28, 7);
	cout << "Target " << target;

	gotoxy(5, 8);
	cout << "Difficulty " << difficulty;

	gotoxy(28, 8);
	cout << "CandiesToCrush " << candiesToCrush;
}

char candySelection(int& rows, int& cols, int& r, int& c)
{
	char key = _getch();
	if ((key == 'w' || key == 'W') && (r > 0 && r <= rows - 1))
	{
		r--;
	}
	else if ((key == 's' || key == 'S') && (r >= 0 && r < rows - 1))
	{
		r++;
	}
	else if ((key == 'a' || key == 'A') && (c > 0 && c <= cols - 1))
	{
		c--;
	}
	else if ((key == 'd' || key == 'D') && (c >= 0 && c < cols - 1))
	{
		c++;
	}
	else if ((key >= 'i' && key <= 'l') || (key >= 'I' && key <= 'L'))
	{
		return key;
	}
	return key;
}

char generateNewCommand(int& NC)
{
	char ch = '\0';
	if (NC == -1 || NC == 6)
	{
		ch = '\0';
	}
	else if (NC == 0)
	{
		ch = '0';
	}
	else if (NC == 1)
	{
		ch = '@';
	}
	else if (NC == 2)
	{
		ch = 'C';
	}
	else if (NC == 3)
	{
		ch = 'R';
	}
	else if (NC == 4)
	{
		ch = 'S';
	}
	else if (NC == 5)
	{
		ch = 'N';
	}
	return ch;
}

void UpdateRC(char key, int& r, int& c)
{
	if (key == 'j' || key == 'J')
	{
		c--;
	}
	else if (key == 'l' || key == 'L')
	{
		c++;
	}
	else if (key == 'i' || key == 'I')
	{
		r--;
	}
	else if (key == 'k' || key == 'K')
	{
		r++;
	}
}

void insertLevels(Slist<Level>& S)
{
	Level Easy(1, 300, 50, 15, 11, 11, "Easy");
	S.insert(Easy);
	Easy.UpdateAttributes(2, 450, 55, 16, 11, 11, "Easy");
	S.insert(Easy);
	Easy.UpdateAttributes(3, 700, 60, 18, 10, 9, "Easy");
	S.insert(Easy);
	Easy.UpdateAttributes(4, 1000, 65, 20, 9, 10, "Easy");
	S.insert(Easy);

	Level Medium(5, 1500, 80, 18, 8, 8, "Medium");
	S.insert(Medium);
	Medium.UpdateAttributes(6, 2200, 90, 22, 8, 9, "Medium");
	S.insert(Medium);
	Medium.UpdateAttributes(7, 3000, 100, 28, 9, 9, "Medium");
	S.insert(Medium);

	Level Hard(8, 3500, 120, 18, 8, 8, "Hard");
	S.insert(Hard);
	Hard.UpdateAttributes(9, 4200, 140, 20, 7, 7, "Hard");
	S.insert(Hard);
	Hard.UpdateAttributes(10, 5000, 150, 25, 6, 6, "Hard");
	S.insert(Hard);
}

bool generateNewBoard()
{
	return true;
}