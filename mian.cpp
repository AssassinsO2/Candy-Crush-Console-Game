#include"header.h"
#include"Board.h"
#include"player.h"

int main()
{
	int xyz = 0;
	int level_counter = 1;
	char* username = new char[20];
	int p_id = 101, At_level = 0, h_score = 0, plevel = 0, cmoney = 0, xp = 0;
	char key;

	Slist<Level> Levels;
	Level currentLevel;
	insertLevels(Levels);

	PrintWelcome();
	setColor(10);
	gotoxy(5, 3);
	cout << "Enter username: ";
	cin.getline(username, 20);

	player P(p_id, username, At_level, h_score, plevel, cmoney, xp);

	setColor(6);
	gotoxy(5, 4);
	cout << "User Successfully Created." << endl;
	Sleep(400);

	while (level_counter != 11)
	{
		system("CLS");
		int rows = 0, cols = 0, r = 0, c = 0, total_score = 0, score = 0;
		int target = 0, moves = 0, CandiesToClear = 0;
		int remainingCandies = 0;
		string difficulty = " ";

		PrintWelcome();
		PrintUserName(username, plevel, h_score, 3);

		setColor(10);
		gotoxy(5, 4);

		int levelSelectorCounter = 0;
		key = levelSelector(levelSelectorCounter, level_counter, username);

		if (key == 'E' || key == 'e')
		{
			break;
		}

		if (levelSelectorCounter < level_counter)
		{
			level_counter = levelSelectorCounter;
		}

		currentLevel.UpdateAttributes(level_counter, 0, 0, 0, 0, 0, " ");
		if (Levels.search(currentLevel))
		{
			target = currentLevel.getTargetScore();
			moves = currentLevel.getMoves();
			CandiesToClear = currentLevel.getCandiesToClear();
			difficulty = currentLevel.getDifficulty();
			rows = currentLevel.getRows();
			cols = currentLevel.getCols();
			moves = currentLevel.getMoves();
		}
		remainingCandies = CandiesToClear;

		system("CLS");
		PrintWelcome();
		PrintUserName(username, plevel, h_score, 5);

		Board B(rows, cols);

		instruction();
		levelDisplay(level_counter, target, difficulty, CandiesToClear);
		scoreDisplay(total_score);
		movesDisplay(moves);
		RemainingCandies(remainingCandies);
		B.display(0, 3, 0);
		cout << endl;

		for (;;)
		{
			if (moves == 0)
			{
				break;
			}

			if (total_score >= target && remainingCandies <= 0)
			{
				break;
			}

			key = candySelection(rows, cols, r, c);

			if (key == 'E' || key == 'e')
			{
				break;
			}
			system("CLS");
			if ((key >= 'i' && key <= 'l') || (key >= 'I' && key <= 'L'))
			{
				if (B.swapPossible(r, c, key) == true)
				{
					moves--;
					B.swapCandy(key, r, c);
					PrintWelcome();
					B.display(r, c, 1);
					B.EvaluateMatch(key, r, c, score, remainingCandies);

					cout << endl;
					setColor(7);
					cout << setw(5) << " ";
					setColor(10);
					cout << "You earned score: " << score << endl;

					total_score = total_score + score;

					scoreDisplay(total_score);
					movesDisplay(moves);

					if (moves == 0)
					{
						break;
					}

					if (total_score >= target && remainingCandies <= 0)
					{
						break;
					}

					if (remainingCandies >= 0)
					{
						RemainingCandies(remainingCandies);
					}
					else
					{
						remainingCandies = 0;
						RemainingCandies(remainingCandies);
					}
					setColor(7);

					for (;;)
					{
						Sleep(1000);
						system("CLS");
						PrintWelcome();
						B.display(r, c, 1);

						int temp_scores = 0;
						bool check = B.autoCrush(temp_scores, remainingCandies);
						total_score = total_score + temp_scores;

						if (check == true)
						{
							setColor(4);
							cout << endl;
							cout << setw(5) << " " << "Crushing more candies." << endl;
							cout << setw(5) << " ";
							setColor(10);
							cout << "You earned score: " << score << endl;
							scoreDisplay(total_score);
							movesDisplay(moves);

							if (remainingCandies >= 0)
							{
								RemainingCandies(remainingCandies);
							}
							else
							{
								remainingCandies = 0;
								RemainingCandies(remainingCandies);
							}
							Sleep(500);
						}

						if (check == false)
						{
							break;
						}
					}
				}
			}
			setColor(7);
			system("CLS");

			PrintWelcome();
			instruction();
			PrintUserName(username, plevel, h_score, 5);
			levelDisplay(level_counter, target, difficulty, CandiesToClear);
			scoreDisplay(total_score);
			movesDisplay(moves);
			if (remainingCandies >= 0)
			{
				RemainingCandies(remainingCandies);
			}
			else
			{
				remainingCandies = 0;
				RemainingCandies(remainingCandies);
			}
			B.display(r, c, 1);
		}

		if (key == 'E' || key == 'e')
		{
			break;
		}

		if (total_score >= target && remainingCandies <= 0)
		{
			Sleep(1000);
			system("CLS");
			PrintWelcome();

			if (total_score > h_score)
			{
				h_score = total_score;
			}
			xp = total_score + 1000;

			levelDisplay(level_counter, target, difficulty, CandiesToClear);

			At_level = level_counter++;
			gotoxy(5, 5);
			setColor(10);
			P.updateCurrent_xp(xp);
			P.updatePlayer_level();
			P.updateAt_level(At_level);
			P.updateCurrent_money(cmoney);
			P.updateHigh_score(h_score);

			plevel = P.getPlayerRank();
			remainingCandies = 0;

			setColor(9);
			PrintUserName(username, plevel, h_score, 3);
			gotoxy(5, 4);
			cout << "Player At Level: " << P.getAt_level() << endl;
			scoreDisplay(total_score);
			movesDisplay(moves);
			if (remainingCandies >= 0)
			{
				RemainingCandies(remainingCandies);
			}
			else
			{
				remainingCandies = 0;
				RemainingCandies(remainingCandies);
			}
			B.display(r, c, 0);

			setColor(10);
			gotoxy(5, 6);
			cout << "CONGRATULATIONS LEVEL COMPLETED" << endl;
			setColor(9);
			gotoxy(5, 22);
			setColor(9);
			cout << "PRESS ANY KEY TO CONTINUE" << endl;
			setColor(0);
			system("pause");
		}

		if (moves == 0)
		{
			instruction();
			PrintUserName(username, plevel, h_score, 5);
			levelDisplay(level_counter, target, difficulty, CandiesToClear);
			xp = total_score;
			P.updateCurrent_xp(xp);
			setColor(4);
			gotoxy(5, 22);
			cout << "OUT OF MOVES                             " << endl;
			setColor(9);
			gotoxy(5, 23);
			cout << "PRESS ANY KEY TO RESTART                 " << endl;
			setColor(0);
			gotoxy(5, 27);
			system("pause");
		}
	}

	system("CLS");
	if (key == 'E' || key == 'e')
	{
		setColor(4);
		gotoxy(5, 3);
		cout << "EXITED SUCCESSFULLY" << endl;
		setColor(7);
	}
	PrintWelcome();
}