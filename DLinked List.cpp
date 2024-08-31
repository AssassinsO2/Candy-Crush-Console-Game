#include"DLinked List.h"

dnode::dnode(Candy c)
{
	candy = c;
	next = nullptr;
	previous = nullptr;
}

Dlist::Dlist()
{
	first = nullptr;
}

bool Dlist::isEmpty()
{
	if (first == nullptr)
	{
		return true;
	}
	return false;
}

void Dlist::insert(Candy c)
{
	dnode* temp = new dnode(c);

	if (isEmpty())
	{
		first = temp;
	}
	else
	{
		dnode* current = first;
		while (current->next != nullptr)
		{
			current = current->next;
		}
		current->next = temp;
		temp->previous = current;
	}
}

void Dlist::ForwardDisplay()
{
	dnode* current = first;
	while (current != nullptr)
	{
		current->candy.display();
		current = current->next;
	}
	cout << endl;
}

int Dlist::FindSize()
{
	int size = 0;
	dnode* current = first;
	if (first == nullptr)
	{
		return 0;
	}
	else
	{
		while (current != nullptr)
		{
			current = current->next;
			size++;
		}
	}
	return size;
}

bool Dlist::colMatch(Candy candy, int limit)
{
	dnode* current = first;
	int counter = 0;
	bool match = false;

	while (counter != limit)
	{
		current = current->next;
		counter++;
	}

	if (current->previous == nullptr || current->next == nullptr)
	{
		match = false;
	}
	else if (current->previous->candy.type == candy.type && current->next->candy.type == candy.type)
	{
		return true;
	}
	else if (current->previous->candy.color % 16 == candy.color % 16 && current->next->candy.color % 16 == candy.color % 16)
	{
		return true;
	}

	if (current->previous == nullptr || current->previous->previous == nullptr)
	{
		match = false;
	}
	else if (current->previous->candy.type == candy.type && current->previous->previous->candy.type == candy.type)
	{
		return true;
	}
	else if (current->previous->candy.color % 16 == candy.color % 16 && current->previous->previous->candy.color % 16 == candy.color % 16)
	{
		return true;
	}

	if (current->next == nullptr || current->next->next == nullptr)
	{
		match = false;
	}
	else if (current->next->candy.type == candy.type && current->next->next->candy.type == candy.type)
	{
		return true;
	}
	else if (current->next->candy.color % 16 == candy.color % 16 && current->next->next->candy.color % 16 == candy.color % 16)
	{
		return true;
	}

	return match;
}

bool Dlist::rowMatch(Candy candy, int limit, char key)
{
	dnode* current = first;
	int counter = 0;
	bool match = false;

	while (counter != limit)
	{
		current = current->next;
		counter++;
	}

	if (key == 'j' || key == 'i' || key == 'J' || key == 'I')
	{
		if (current->previous == nullptr)
		{
			match = false;
		}
		else if (current->previous->previous->candy.type == current->candy.type && current->previous->previous->previous->candy.type == current->candy.type)
		{
			return true;
		}
		else if (current->previous->previous->candy.color % 16 == current->candy.color % 16 && current->previous->previous->previous->candy.color % 16 == current->candy.color % 16)
		{
			return true;
		}
	}

	else if (key == 'l' || key == 'k' || key == 'L' || key == 'K')
	{
		if (current->next == nullptr || current->next->next == nullptr || current->next->next->next == nullptr)
		{
			match = false;
		}
		else if (current->next->next->candy.type == current->candy.type && current->next->next->next->candy.type == current->candy.type)
		{
			return true;
		}
		else if (current->next->next->candy.color % 16 == current->candy.color % 16 && current->next->next->next->candy.color % 16 == current->candy.color % 16)
		{
			return true;
		}
	}
	return match;
}

Dlist Dlist::FindMatches(int& StartIndex, int& EndIndex, int& CandiesToCrush)
{
	dnode* current = first;
	int m = 0, n = 0, i = 0;
	int matchedCandies = 0;
	Candy* arr = new Candy[5];

	while (current->next->next != nullptr)
	{
		if ((current->candy.type == current->next->candy.type && current->next->next->candy.type == current->candy.type) ||
			(current->candy.color % 16 == current->next->candy.color % 16 && current->next->next->candy.color % 16 == current->candy.color % 16))
		{
			if (m == 0)
			{
				StartIndex = n;
			}
			m++;

			arr[i].SetAttributes(current->candy);
			arr[i + 1].SetAttributes(current->next->candy);
			arr[i + 2].SetAttributes(current->next->next->candy);
			i++;
		}
		current = current->next;
		n++;
	}

	Dlist matches;

	if (m == 1)
	{
		matchedCandies = 3;
	}
	else if (m == 2)
	{
		matchedCandies = 4;
	}
	else if (m == 3)
	{
		matchedCandies = 5;
	}
	else
	{
		matchedCandies = 0;
		StartIndex = 0;
		EndIndex = 0;
		return matches;
	}

	CandiesToCrush = CandiesToCrush - matchedCandies;
	EndIndex = StartIndex + matchedCandies - 1;

	if (matchedCandies != 0)
	{
		for (int j = 0; j < matchedCandies; j++)
		{
			matches.insert(arr[j]);
		}
	}

	return matches;
}

int Dlist::calPoints(int& points)
{
	dnode* current = first;
	int* arr = new int[4];

	for (int i = 0; i < 4; i++)
	{
		arr[i] = 0;
	}

	if (first == nullptr)
	{
		return -1;
	}
	else
	{
		while (current != nullptr)
		{
			Candy candy;
			candy.type = current->candy.type;
			if (candy.type == '#' || candy.type == '$' || candy.type == '%' || candy.type == '&' || candy.type == '*')
			{
				arr[0]++;
			}
			else if (current->candy.type == '0')
			{
				arr[1]++;
			}
			else if (current->candy.type == '@')
			{
				arr[2]++;
			}

			current = current->next;
		}
	}

	if (arr[0] == 3 && arr[1] == 0 && arr[2] == 0)
	{
		// Case 1
		points = 30;
		return 6;
	}
	else if (arr[0] == 3 && arr[1] == 1)
	{
		// Case 2
		points = 200;
		return 2;
	}
	else if (arr[0] == 2 && arr[1] == 1)
	{
		// Case 3
		points = 100;
		return 2;
	}
	else if (arr[0] == 1 && arr[2] == 1)
	{
		// Case 4
		points = 150;
		return 3;
	}
	else if (arr[0] == 5)
	{
		// Case 5
		points = 100;
		return 1;
	}
	else if (arr[0] == 4)
	{
		// Case 6
		points = 50;
		return 0;
	}
	else if (arr[1] == 1 && arr[2] == 1)
	{
		// Case 7
		points = 300;
		return 4;
	}
	else if (arr[2] == 2)
	{
		// Case 8
		points = 500;
		return 5;
	}
	else if (arr[0] == 1 && arr[1] == 2)
	{
		// Case 9
		points = 200;
		return 2;
	}
	return -1;
}

void Dlist::removeDup()
{
	Candy candies[] = {
		Candy('#', 4),
		Candy('$', 6),
		Candy('%', 14),
		Candy('&', 10),
		Candy('*', 1)
	};

	dnode* current = first;

	if (first == nullptr)
	{
		return;
	}
	else
	{
		while (current != nullptr)
		{
			if (current->candy.type == current->next->candy.type && current->candy.type == current->next->next->candy.type)
			{
				for (int i = 0; i < 5; i++)
				{
					if (current->candy.type != candies[i].type && current->previous->candy.type != candies[i].type)
					{
						current->candy = candies[i];
						break;
					}
				}
			}
			if (current->next->next == nullptr)
			{
				break;
			}
			current = current->next;
		}
	}
}