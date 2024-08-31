#include"Board.h"
#include"header.h"

void shuffleCandies(Candy candies[], int size)
{
	random_device rd;
	default_random_engine rng(rd());
	shuffle(candies, candies + size, rng);
}

Board::Board(int r, int c)
{
	rows = r;
	cols = c;
	board = new Candy * [rows];
	for (int i = 0; i < rows; i++)
	{
		board[i] = new Candy[cols];
	}

	Candy candies[] = {
		Candy('#', 4),
		Candy('$', 6),
		Candy('%', 5),
		Candy('&', 10),
		Candy('*', 1)
	};

	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			shuffleCandies(candies, 5);
			board[i][j] = candies[0];
		}
	}

	removeDup();
}

Board::~Board()
{
	for (int i = 0; i < rows; i++)
	{
		delete[] board[i];
	}
	delete[] board;
}

void Board::removeDup()
{
	Candy candies[] = {
		Candy('#', 4),
		Candy('$', 6),
		Candy('%', 5),
		Candy('&', 10),
		Candy('*', 1)
	};

	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols - 2; j++)
		{
			if (board[i][j].type == board[i][j + 1].type)
			{
				if (board[i][j + 1].type == board[i][j + 2].type)
				{
					for (int k = 0; k < 5; k++)
					{
						if (i == 0)
						{
							if (board[i][j + 1].type != candies[k].type && board[i + 1][j + 1].type != candies[k].type)
							{
								board[i][j + 1] = candies[k];
								break;
							}
						}
						else if (i == rows - 1)
						{
							if (board[i - 1][j + 1].type != candies[k].type && board[i][j + 1].type != candies[k].type)
							{
								board[i][j + 1] = candies[k];
								break;
							}
						}
						else
						{
							if (board[i - 1][j + 1].type != candies[k].type && board[i][j + 1].type != candies[k].type && board[i + 1][j + 1].type != candies[k].type)
							{
								board[i][j + 1] = candies[k];
								break;
							}
						}
					}
				}
			}
		}
	}

	for (int j = 0; j < cols; j++)
	{
		for (int i = 0; i < rows - 2; i++)
		{
			if (board[i][j].type == board[i + 1][j].type)
			{
				if (board[i + 1][j].type == board[i + 2][j].type)
				{
					for (int k = 0; k < 5; k++)
					{
						if (j == 0)
						{
							if (board[i + 1][j].type != candies[k].type && board[i + 1][j + 1].type != candies[k].type)
							{
								board[i + 1][j] = candies[k];
								break;
							}
						}
						else if (j == cols - 1)
						{
							if (board[i + 1][j - 1].type != candies[k].type && board[i + 1][j].type != candies[k].type)
							{
								board[i + 1][j] = candies[k];
								break;
							}
						}
						else
						{
							if (board[i + 1][j - 1].type != candies[k].type && board[i + 1][j].type != candies[k].type && board[i + 1][j + 1].type != candies[k].type)
							{
								board[i + 1][j] = candies[k];
								break;
							}
						}
					}
				}
			}
		}
	}
}

bool Board::autoCrush(int& points, int& CandiesToCrush)
{
	system("CLS");
	PrintWelcome();
	display(0, 0, 0);

	int r = -1, c = -1, startIndex = -1, endIndex = -1, NC = -2, matchedCandies = 0;
	bool match = false;
	Dlist rowList, colList;
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols - 2; j++)
		{
			if ((board[i][j].type == board[i][j + 1].type) && (board[i][j].type == board[i][j + 2].type)
				|| (board[i][j].color % 16 == board[i][j + 1].color % 16) && (board[i][j].color % 16 == board[i][j + 2].color % 16))
			{
				r = i;
				c = j;
				if (startIndex == -1)
				{
					startIndex = j;
				}
				endIndex = j + 2;

				for (int k = 0; k < cols; k++)
				{
					rowList.insert(board[i][k]);
				}

				match = true;
			}
			if (match == true)
			{
				break;
			}
		}
		if (match == true)
		{
			break;
		}
	}

	matchedCandies = endIndex - startIndex + 1;
	CandiesToCrush = CandiesToCrush - matchedCandies;

	if (rowList.FindSize() > 0)
	{
		Dlist matchesInRow = rowList.FindMatches(startIndex, endIndex, CandiesToCrush);

		if (matchesInRow.FindSize() > 0)
		{
			NC = matchesInRow.calPoints(points);
			char next = generateNewCommand(NC);
			replaceCandiesForRow(r, c, next, startIndex, endIndex);
		}
	}

	if (match == true)
	{
		return true;
	}

	for (int j = 0; j < cols; j++)
	{
		for (int i = 0; i < rows - 2; i++)
		{
			if ((board[i][j].type == board[i + 1][j].type) && (board[i][j].type == board[i + 2][j].type)
				|| (board[i][j].color % 16 == board[i + 1][j].color % 16) && (board[i][j].color % 16 == board[i + 2][j].color % 16))
			{
				r = i;
				c = j;
				if (startIndex == -1)
				{
					startIndex = i;
				}
				endIndex = i + 2;

				for (int k = 0; k < rows; k++)
				{
					colList.insert(board[k][j]);
				}
				match = true;
			}
			if (match == true)
			{
				break;
			}
		}
		if (match == true)
		{
			break;
		}
	}

	matchedCandies = endIndex - startIndex + 1;
	CandiesToCrush = CandiesToCrush - matchedCandies;

	if (colList.FindSize() > 0)
	{
		Dlist matchesInCol = colList.FindMatches(startIndex, endIndex, CandiesToCrush);

		if (matchesInCol.FindSize() > 0)
		{
			NC = matchesInCol.calPoints(points);
			char next = generateNewCommand(NC);
			replaceCandiesForCol(r, c, next, startIndex, endIndex);
		}
	}

	if (rowList.FindSize() == 0 && colList.FindSize() == 0)
	{
		return false;
	}

	return match;
}

void Board::display(int r, int c, int b)
{
	int s = 10;
	int save_color = board[r][c].color;
	if (b != 0)
	{
		board[r][c].color = board[r][c].color + 112;
	}
	for (int i = 0; i < rows; i++)
	{
		gotoxy(5, s);
		for (int j = 0; j < cols; j++)
		{
			board[i][j].display();
		}
		cout << endl;
		s++;
	}
	board[r][c].color = save_color;
}

void Board::swapCandy(char& key, int& r, int& c)
{
	Candy temp = board[r][c];
	if (key == 'i' || key == 'I')
	{
		board[r][c] = board[r - 1][c];
		board[r - 1][c] = temp;
	}
	else if (key == 'k' || key == 'K')
	{
		board[r][c] = board[r + 1][c];
		board[r + 1][c] = temp;
	}
	else if (key == 'j' || key == 'J')
	{
		board[r][c] = board[r][c - 1];
		board[r][c - 1] = temp;
	}
	else if (key == 'l' || key == 'L')
	{
		board[r][c] = board[r][c + 1];
		board[r][c + 1] = temp;
	}
}

bool Board::swapPossible(int& r, int& c, char& key)
{
	Dlist rowList, colList;

	if (key == 'i' || key == 'I')
	{
		if (r > 2)
		{
			for (int i = 0; i < rows; i++)
			{
				colList.insert(board[i][c]);
			}

			if (colList.rowMatch(board[r][c], r, key))
			{
				return true;
			}
		}

		if (r > 0)
		{
			for (int i = 0; i < cols; i++)
			{
				rowList.insert(board[r - 1][i]);
			}

			if (rowList.colMatch(board[r][c], c))
			{
				return true;
			}
		}
	}
	else if (key == 'k' || key == 'K')
	{
		if (r < rows - 3)
		{
			for (int i = 0; i < rows; i++)
			{
				colList.insert(board[i][c]);
			}

			if (colList.rowMatch(board[r][c], r, key))
			{
				return true;
			}
		}
		if (r < rows - 1)
		{
			for (int i = 0; i < cols; i++)
			{
				rowList.insert(board[r + 1][i]);
			}

			if (rowList.colMatch(board[r][c], c))
			{
				return true;
			}
		}
	}
	else if (key == 'j' || key == 'J')
	{
		if (c > 0)
		{
			for (int i = 0; i < rows; i++)
			{
				colList.insert(board[i][c - 1]);
			}

			if (colList.colMatch(board[r][c], r))
			{
				return true;
			}
		}
		if (c > 2)
		{
			for (int i = 0; i < cols; i++)
			{
				rowList.insert(board[r][i]);
			}

			if (rowList.rowMatch(board[r][c], c, key))
			{
				return true;
			}
		}
	}
	else if (key == 'l' || key == 'L')
	{
		if (c < cols - 1)
		{
			for (int i = 0; i < rows; i++)
			{
				colList.insert(board[i][c + 1]);
			}

			if (colList.colMatch(board[r][c], r))
			{
				return true;
			}
		}
		if (c < cols - 3)
		{
			for (int i = 0; i < cols; i++)
			{
				rowList.insert(board[r][i]);
			}

			if (rowList.rowMatch(board[r][c], c, key))
			{
				return true;
			}
		}
	}

	return false;
}

void Board::EvaluateMatch(char& key, int r, int c, int& points, int& CandiesToCrush)
{
	int StartIndex = -1, EndIndex = -1;
	Dlist rowList, colList;

	UpdateRC(key, r, c);

	for (int i = 0; i < rows; i++)
	{
		colList.insert(board[i][c]);
	}

	for (int i = 0; i < cols; i++)
	{
		rowList.insert(board[r][i]);
	}

	if (rowList.FindSize() > 0)
	{
		Dlist matchesInRow = rowList.FindMatches(StartIndex, EndIndex, CandiesToCrush);

		if (matchesInRow.FindSize() > 0)
		{
			int NC = matchesInRow.calPoints(points);
			char next = generateNewCommand(NC);
			replaceCandiesForRow(r, c, next, StartIndex, EndIndex);
		}
	}

	if (colList.FindSize() > 0)
	{
		Dlist matchesInCol = colList.FindMatches(StartIndex, EndIndex, CandiesToCrush);

		if (matchesInCol.FindSize() > 0)
		{
			int NC = matchesInCol.calPoints(points);
			char next = generateNewCommand(NC);
			replaceCandiesForCol(r, c, next, StartIndex, EndIndex);
		}
	}
}

void Board::replaceCandiesForRow(int& r, int& c, char& next, int SI, int EI)
{
	queue<Candy> Q1;
	int middle = (SI + EI) / 2;

	if (EI - SI == 3)
	{
		middle++;
	}

	Candy oldCandy = board[r][middle];

	if (next == '0' || next == '@' || next == 'C' || next == '\0')
	{

		if (next == 'C')
		{
			// clear row 
			// shift candies from up
			for (int i = r - 1; i >= 0; i--)
			{
				for (int j = 0; j < cols; j++)
				{
					Q1.enqueue(board[i][j]);
				}

				for (int k = 0; k < cols; k++)
				{
					board[i + 1][k] = Q1.peek();
					Q1.dequeue();
				}
			}
			SI = 0;
			EI = cols - 1;
			middle = (SI + EI) / 2;
			SpecialMoves(next, r, c, oldCandy, SI, EI, middle, 'r');
		}
		else
		{
			for (int i = r - 1; i >= 0; i--)
			{
				for (int j = SI; j <= EI; j++)
				{
					Q1.enqueue(board[i][j]);
				}
				for (int k = SI; k <= EI; k++)
				{
					Candy candy = Q1.peek();
					Q1.dequeue();
					board[i + 1][k] = candy;
				}
			}
			SpecialMoves(next, r, c, oldCandy, SI, EI, middle, 'r');
		}
	}
}

void Board::replaceCandiesForCol(int& r, int& c, char& next, int SI, int EI)
{
	queue<Candy> Q1;
	int middle = (SI + EI) / 2;
	int matched_candies = EI - SI + 1;

	if (EI - SI == 3)
	{
		middle++;
	}

	Candy oldCandy = board[middle][c];

	if (next == '0' || next == '@' || next == 'C' || next == '\0')
	{
		int replace_pos = EI;
		if (next == '@' || next == '0')
		{
			replace_pos--;
		}

		if (next == 'C')
		{
			// clear col 
			SI = 0;
			EI = cols - 1;
			middle = (SI + EI) / 2;
			SpecialMoves(next, r, c, oldCandy, SI, EI, EI, 'c');
		}
		else
		{
			for (int i = SI - 1; i >= 0; i--)
			{
				Q1.enqueue(board[i][c]);
			}

			int size = Q1.GetCurrentSize();

			if (size == matched_candies)
			{
				for (int i = replace_pos; size != 0; i--)
				{
					Candy candy = Q1.peek();
					Q1.dequeue();
					board[i][c] = candy;
					size = Q1.GetCurrentSize();
				}
			}
			else
			{
				for (int i = replace_pos; size != 0; i--)
				{
					Candy candy = Q1.peek();
					Q1.dequeue();
					board[i][c] = candy;
					size = Q1.GetCurrentSize();
				}
			}
			SpecialMoves(next, r, c, oldCandy, SI, EI, EI, 'c');
		}
	}
}

void Board::SpecialMoves(char& next, int& r, int& c, Candy& oldCandy, int SI, int EI, int& middle, char secondKey)
{
	int newRow = r, newCol = c;
	Candy newCandy;

	if (secondKey == 'r')
	{
		newCol = middle;
	}
	else if (secondKey == 'c')
	{
		//using middle as EI
		newRow = middle;
	}

	if (next == '0')
	{
		// add stripped.
		newCandy.color = oldCandy.color + 176;
		newCandy.type = '0';
		board[newRow][newCol] = newCandy;
	}
	else if (next == '@')
	{
		// add colour bomb.
		newCandy.color = 246;
		newCandy.type = '@';
		board[newRow][newCol] = newCandy;
	}

	// generate new candies 
	if (next == '0' || next == '@' || next == 'C' || next == '\0')
	{
		GenerateNewCandies(r, c, SI, EI, secondKey);
	}

	if (next == 'R')
	{
		// remove all one type 
	}
	else if (next == 'S')
	{
		// convert 1 type of candies to 0
	}
	else if (next == 'N')
	{
		// blast and create new board
	}
}

void Board::GenerateNewCandies(int& r, int& c, int SI, int EI, char& secondKey)
{
	Candy candies[] = {
		Candy('#', 4),
		Candy('$', 6),
		Candy('%', 5),
		Candy('&', 10),
		Candy('*', 1)
	};

	int size = EI - SI + 1;

	if (secondKey == 'r')
	{
		size++;
	}
	else if (secondKey == 'c')
	{
		if (EI - SI == 2)
		{
			size++;
		}
	}

	Candy* boardCandies = new Candy[size + 1];
	queue<Candy> Q1;

	for (int i = SI, j = 0; i <= EI; i++)
	{
		shuffleCandies(candies, 5);
		boardCandies[j] = candies[0];
		j++;
	}

	for (int i = 0; i < size - 2; i++)
	{
		if (boardCandies[i].type == boardCandies[i + 1].type && boardCandies[i].type == boardCandies[i + 2].type)
		{
			for (int k = 0; k < 5; k++)
			{
				if (candies[k].type != boardCandies[i].type && candies[k].type != boardCandies[i - 1].type)
				{
					boardCandies[i] = candies[k];
				}
			}
		}
	}

	for (int i = 0; i < size; i++)
	{
		Q1.enqueue(boardCandies[i]);
	}

	if (secondKey == 'r')
	{
		for (int i = SI; i <= EI; i++)
		{
			board[0][i] = Q1.peek();
			Q1.dequeue();
		}
	}
	else if (secondKey == 'c')
	{
		int p = EI - SI + 1;
		if (EI - SI == 3 || EI - SI == 4)
		{
			for (int i = p - 2; i >= 0; i--)
			{
				board[i][c] = Q1.peek();
				Q1.dequeue();
			}
		}
		else
		{
			for (int i = p - 1; i >= 0; i--)
			{
				board[i][c] = Q1.peek();
				Q1.dequeue();
			}
		}
	}
}