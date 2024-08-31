#include"queue.h"

template<class T>
queue<T>::queue()
{
	front = 0;
	rear = -1;
}

template<class T>
bool queue<T>::isEmpty()
{
	if (rear == -1)
	{
		return true;
	}
	return false;
}

template<class T>
bool queue<T>::isFull()
{
	if (rear == max)
	{
		return true;
	}
	else
	{
		return false;
	}
}

template<class T>
void queue<T>::enqueue(T v)
{
	if (!isFull())
	{
		rear++;
		array[rear] = v;
	}
}

template<class T>
void queue<T>::dequeue()
{
	if (!isEmpty())
	{
		if (front == rear)
		{
			front = 0;
			rear = -1;
		}
		else
		{
			front++;
		}
	}
}

template<class T>
T queue<T>::peek()
{
	if (!isEmpty())
	{
		T T1 = array[front];
		return T1;
	}
	else
	{
		cout << "Queue is empty." << endl;
	}
}


template<class T>
int queue<T>::GetCurrentSize()
{
	return rear + 1;
}